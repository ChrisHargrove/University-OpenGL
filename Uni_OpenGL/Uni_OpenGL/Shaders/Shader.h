////////////////////////////////////////////////////////////
//
// Shader
// Author - Chris Hargrove
// Date   - 17/10/2017
//
////////////////////////////////////////////////////////////
#ifndef SHADER_H
#define SHADER_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>

////////////////////////////////////////////////////////////
/// Engine Shader
/// --Handles the creation of shader objects aswell as
/// --reading vertex and fragment shaders into memory
/// --and compiling them into a program.
////////////////////////////////////////////////////////////
class Shader
{
public:
	////////////////////////////////////////////////////////////
	/// Default Constructor.
	////////////////////////////////////////////////////////////
	Shader(const std::string FileName);

	////////////////////////////////////////////////////////////
	/// Default Destructor.
	////////////////////////////////////////////////////////////
	~Shader();

	////////////////////////////////////////////////////////////
	/// Sets this Shader to be the current shader to use for 
	/// Rendering on the GPU.
	////////////////////////////////////////////////////////////
	void Use();

	////////////////////////////////////////////////////////////
	/// Sets a boolean variable inside the Shader program to a 
	/// specified value.
	/// --Name-- The name of the variable inside the Shader Program
	/// --Value-- The value to set the variable to.
	////////////////////////////////////////////////////////////
	void SetBool(const std::string &Name, bool Value) const;

	////////////////////////////////////////////////////////////
	/// Sets an integer variable inside the Shader program to a 
	/// specified value.
	/// --Name-- The name of the variable inside the Shader Program
	/// --Value-- The value to set the variable to.
	////////////////////////////////////////////////////////////
	void SetInt(const std::string &Name, int Value) const;

	////////////////////////////////////////////////////////////
	/// Sets a float variable inside the Shader program to a 
	/// specified value.
	/// --Name-- The name of the variable inside the Shader Program
	/// --Value-- The value to set the variable to.
	////////////////////////////////////////////////////////////
	void SetFloat(const std::string &Name, float Value) const;

private:
	////////////////////////////////////////////////////////////
	/// Utility function to check for compilation errors
	/// --Shader-- The shader ID hat you want to check.
	/// --Type-- The type of shader that your checking.
	////////////////////////////////////////////////////////////
	bool CheckCompileErrors(unsigned int Shader, std::string Type);

	////////////////////////////////////////////////////////////
	// Member Data
	////////////////////////////////////////////////////////////
	unsigned int ID;	// ID for the shader program in memory
};

#endif