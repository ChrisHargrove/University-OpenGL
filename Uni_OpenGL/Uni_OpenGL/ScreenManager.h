////////////////////////////////////////////////////////////
//
// Screen Manager
// Author - Chris Hargrove
// Date   - 10/10/2017
//
////////////////////////////////////////////////////////////
#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SDL\SDL.h>
#include <GLEW\glew.h>

////////////////////////////////////////////////////////////
/// Engine Screen Manager
/// --Handles everything to do with the screen from 
/// --initializing to destruction.
/// --Setup using the Singleton Pattern.
////////////////////////////////////////////////////////////
class ScreenManager
{
public:
	////////////////////////////////////////////////////////////
	/// Default Constructor.
	////////////////////////////////////////////////////////////
	ScreenManager();

	////////////////////////////////////////////////////////////
	/// Default Destructor.
	////////////////////////////////////////////////////////////
	~ScreenManager();

	////////////////////////////////////////////////////////////
	/// Initialises the window, and sets starter variables.
	///
	/// --Title--  The Title to be displayed in Window bar.
	/// --Width--  The Window Width   --Default = 800.
	/// --Height-- The Window Height  --Defualt = 600.
	/// --CoreMode-- If OpenGL should run in Core mode or not. --Default = true.
	////////////////////////////////////////////////////////////
	bool Initialize(char* Title, int Width = 800, int Height = 600, bool CoreMode = true);

	////////////////////////////////////////////////////////////
	/// Closes the window and free's all associated memory.
	////////////////////////////////////////////////////////////
	void Close();

	////////////////////////////////////////////////////////////
	/// Clears the screen buffer to clear color. Also clears
	/// screen depth buffer.
	////////////////////////////////////////////////////////////
	void Clear();

	////////////////////////////////////////////////////////////
	/// Swaps buffers in memory to display to the window.
	////////////////////////////////////////////////////////////
	void SwapBuffers();

	////////////////////////////////////////////////////////////
	/// Enables VSync for the screen. Defaults to true;
	/// --VSync-- True or false.
	////////////////////////////////////////////////////////////
	bool EnableVSync(bool VSync = true);

	////////////////////////////////////////////////////////////
	/// Sets the screen's clear color. Default color is Black.
	///
	/// --Red-- Red value for color 0.0f - 1.0f.
	/// --Green-- Green value for color 0.0f - 1.0f.
	/// --Blue-- Blue value for color 0.0f - 1.0f.
	/// --Alpha-- Alpha value for color 0.0f - 1.0f.
	///
	////////////////////////////////////////////////////////////
	void SetClearColor(float Red, float Green, float Blue, float Alpha);

	////////////////////////////////////////////////////////////
	/// Sets the version of OpenGL to use. Defaults to OpenGL 3.3.
	/// --Major-- The major version of OpenGL --Default = 3.
	/// --Minor-- The minor version of OpenGL --Default = 3.
	////////////////////////////////////////////////////////////
	void SetOpenGLVersion(int Major = 3, int Minor = 3);

	////////////////////////////////////////////////////////////
	/// Gets a pointer to the SDL_Window.
	////////////////////////////////////////////////////////////
	SDL_Window* GetWindow();

	////////////////////////////////////////////////////////////
	/// Gets a pointer to the SDL_GLContext.
	////////////////////////////////////////////////////////////
	SDL_GLContext* GetContext();

	////////////////////////////////////////////////////////////
	/// Provides access to the only instance of the screen
	/// manager.
	////////////////////////////////////////////////////////////
	static ScreenManager* Instance() {
		return &_Instance;
	};

private:
	////////////////////////////////////////////////////////////
	// Member Data
	////////////////////////////////////////////////////////////
	static ScreenManager _Instance; // Static Instance of ScreenManager

	SDL_Window*		_Window;		// Pointer to SDL window.
	SDL_GLContext	_Context;		// Pointer to OpenGL Context.

	bool _VersionSet;				// Flag to see if a OpenGL version has been set.
	int _GL_VERSION_MAJOR;			// The Major version of OpenGL to use.
	int _GL_VERSION_MINOR;			// The Minor version of OpenGL to use.

};

#endif