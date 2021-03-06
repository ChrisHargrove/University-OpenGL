#include "Mesh.h"
#include "ShaderManager.h"



Mesh::Mesh(std::vector<ComplexVertex> vertices, std::vector<unsigned int> indices, std::vector<MeshTexture> textures, std::string shader)
{
    _Vertices = vertices;
    _Indices = indices;
    _Textures = textures;

    _Shader = shader;
	_Shininess = 8;

    _VertexArray.Create(VAO);
    _VertexBuffer.Create(VBO);
    _ElementBuffer.Create(EBO);

    _VertexArray.Bind();
    _VertexBuffer.Fill(sizeof(ComplexVertex) * _Vertices.size(), &_Vertices[0], STATIC);

    _VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(_Shader)->GetID(), "aPos", 3, VT_FLOAT, sizeof(ComplexVertex));
    _VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(_Shader)->GetID(), "aNormal", 3, VT_FLOAT, sizeof(ComplexVertex), 3 * sizeof(float));
    _VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(_Shader)->GetID(), "aTexCoords", 2, VT_FLOAT, sizeof(ComplexVertex), 6 * sizeof(float));
    _VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(_Shader)->GetID(), "aTangent", 3, VT_FLOAT, sizeof(ComplexVertex), 8 * sizeof(float));
    _VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(_Shader)->GetID(), "aBiTangent", 3, VT_FLOAT, sizeof(ComplexVertex), 11 * sizeof(float));

    _ElementBuffer.Fill(sizeof(unsigned int) * _Indices.size(), &_Indices[0], STATIC);

    _VertexArray.Unbind();
}

void Mesh::Render(std::string shader)
{
	//was trying to implement shadows but ran out of time so this if block is not used.
	if (shader != "") {
		_VertexArray.Bind();
		_VertexBuffer.Bind();
		_VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(shader)->GetID(), "aPos", 3, VT_FLOAT, sizeof(ComplexVertex));
		_VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(shader)->GetID(), "aNormal", 3, VT_FLOAT, sizeof(ComplexVertex), 3 * sizeof(float));
		_VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(shader)->GetID(), "aTexCoords", 2, VT_FLOAT, sizeof(ComplexVertex), 6 * sizeof(float));
		_VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(shader)->GetID(), "aTangent", 3, VT_FLOAT, sizeof(ComplexVertex), 8 * sizeof(float));
		_VertexBuffer.AddAttribPointer(ShaderManager::Instance()->GetShader(shader)->GetID(), "aBiTangent", 3, VT_FLOAT, sizeof(ComplexVertex), 11 * sizeof(float));

	}
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    unsigned int normalNr = 1;
    unsigned int heightNr = 1;
    for (unsigned int i = 0; i < _Textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
                                          // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = _Textures[i]._Type;
        if (name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if (name == "texture_specular")
            number = std::to_string(specularNr++);
        else if (name == "texture_normal")
            number = std::to_string(normalNr++);
        else if (name == "texture_height")
            number = std::to_string(heightNr++);

        ShaderManager::Instance()->GetShader(_Shader)->SetInt(("material." + name + number).c_str(), (int)i);
		ShaderManager::Instance()->GetShader(_Shader)->SetFloat("material.shininess", _Shininess);
        glBindTexture(GL_TEXTURE_2D, _Textures[i]._ID);
    }

    _VertexArray.Bind();
    glDrawElements(GL_TRIANGLES, _Indices.size(), GL_UNSIGNED_INT, 0);
    _VertexArray.Unbind();

    glActiveTexture(GL_TEXTURE0);
}

void Mesh::SetShininess(float value)
{
	_Shininess = value;
}
