////////////////////////////////////////////////////////////
//
// Input Manager
// Author - Chris Hargrove
// Date   - 11/10/2017
//
////////////////////////////////////////////////////////////
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <map>

////////////////////////////////////////////////////////////
/// KeyEvent Struct
/// --Keycode-- The integer number representing the key.
/// --State-- The current state of key, eg. Pressed or Released.
/// --Mod-- The key modifier if applicable, eg.Shift
////////////////////////////////////////////////////////////
struct KeyEvent {
	int Keycode;
	int State;
	int Mod;
};

////////////////////////////////////////////////////////////
/// WindowEvent Struct
/// --WindowID-- The integer ID of the window that made event.
/// --Type-- The type of event.
/// --Data1-- First piece of data associated to event.
/// --Data2-- Second piece of data associated to event.
////////////////////////////////////////////////////////////
struct WindowEvent {
	int WindowID;
	int Type;
	int Data1;
	int Data2;
};

////////////////////////////////////////////////////////////
/// MouseButtonEvent Struct
/// --Button-- The integer number representing the button.
/// --State-- The current state of button, eg. Pressed or Released.
/// --Clicks-- The number of clicks, so double or not.
////////////////////////////////////////////////////////////
struct MouseButtonEvent {
	int Button;
	int State;
	int Clicks;
};

////////////////////////////////////////////////////////////
/// MouseMoveEvent Struct
/// --xPos-- The X position of mouse
/// --yPos-- The Y position of mouse
/// --xRel-- The Relative X position from previous position.
/// --yRel-- The Relative Y position from previous position.
/// --HasMoved-- Boolean if the mouse has moved.
////////////////////////////////////////////////////////////
struct MouseMoveEvent {
	double xPos;
	double yPos;
	double xRel;
	double yRel;
	bool HasMoved;

	MouseMoveEvent() {
		HasMoved = false;
	}
};

////////////////////////////////////////////////////////////
/// MouseScrollEvent Struct
/// --X-- The X movement of mouse wheel
/// --Y-- The Y movement of mouse wheel
/// --Direction-- If Direction of wheel movement is flipped.
/// --HasMoved-- Boolean if the mouse wheel has moved.
////////////////////////////////////////////////////////////
struct MouseScrollEvent {
	double X;
	double Y;
	int Direction;
	bool HasMoved;

	MouseScrollEvent() {
		HasMoved = false;
	}
};


////////////////////////////////////////////////////////////
/// Engine Input Manager
/// --Handles all keyboard and mouse input from the user.
/// --Also implements individual key presses without repeat.
////////////////////////////////////////////////////////////
class InputManager
{
public:
	

	////////////////////////////////////////////////////////////
	/// Updates the InputManager and polls for all events.
	////////////////////////////////////////////////////////////
	void Update();

	////////////////////////////////////////////////////////////
	/// Checks to see if a key has been pressed once.
	/// --Key-- The key to check.
	////////////////////////////////////////////////////////////
	bool IsKeyPressed(int Key);

	////////////////////////////////////////////////////////////
	/// Checks to see if a key has been released.
	/// --Key-- The key to check.
	////////////////////////////////////////////////////////////
	bool IsKeyReleased(int Key);

	////////////////////////////////////////////////////////////
	/// Checks to see if a key is being held.
	/// --Key-- The key to check.
	////////////////////////////////////////////////////////////
	bool IsKeyHeld(int Key);

	////////////////////////////////////////////////////////////
	/// Checks to see if a mouse button has been pressed.
	/// --Button-- The key to check.
	////////////////////////////////////////////////////////////
	bool IsButtonPressed(int Button);

	////////////////////////////////////////////////////////////
	/// Checks to see if a key has been released.
	/// --Button-- The key to check.
	////////////////////////////////////////////////////////////
	bool IsButtonReleased(int Button);

	////////////////////////////////////////////////////////////
	/// Checks to see if the mouse has moved.
	////////////////////////////////////////////////////////////
	bool HasMouseMoved();

	////////////////////////////////////////////////////////////
	/// Gets the data associated with the mouse movement.
	////////////////////////////////////////////////////////////
	const MouseMoveEvent GetMouseMove();

	////////////////////////////////////////////////////////////
	/// Checks to see if the mouse wheel has been scrolled.
	////////////////////////////////////////////////////////////
	bool HasScrolled();

	////////////////////////////////////////////////////////////
	/// Gets X scroll value.
	////////////////////////////////////////////////////////////
	double GetXScroll();

	////////////////////////////////////////////////////////////
	/// Gets Y scroll value.
	////////////////////////////////////////////////////////////
	double GetYScroll();

    ////////////////////////////////////////////////////////////
    /// Checks to see if a application quit has been recieved.
    ////////////////////////////////////////////////////////////
    bool HasQuit();

	////////////////////////////////////////////////////////////
	/// Checks to see if there is a window event, eg. Close, Resize, etc.
	/// --WindowEvent-- The window event to check for.
	////////////////////////////////////////////////////////////
	bool CheckForWinEvent(int windowEvent);

	////////////////////////////////////////////////////////////
	/// Gets WindowEvent data
	///	/// --WindowEvent-- The window event recieve data from.
	////////////////////////////////////////////////////////////
	WindowEvent GetWinEvent(int windowEvent);

	////////////////////////////////////////////////////////////
	/// Will Confine mouse pointer to the window, and hide cursor.
	////////////////////////////////////////////////////////////
	void GrabMouse();

	////////////////////////////////////////////////////////////
	/// Will Release mouse grab and will reshow cursor.
	////////////////////////////////////////////////////////////
	void ReleaseMouse();

	void RequestQuit();
	void ResetMouseEvents();

	////////////////////////////////////////////////////////////
	/// Provides access to the only instance of the screen
	/// manager.
	////////////////////////////////////////////////////////////
	static InputManager* Instance() {
		return &_Instance;
	};

private:
	InputManager();
	~InputManager();
	InputManager(const InputManager&) {}

	////////////////////////////////////////////////////////////
	/// Adds a keyboard event to the InputManager
	/// --Keycode-- The integer number representing the key.
	/// --State-- The current state of key, eg. Pressed or Released.
	/// --Mod-- The key modifier if applicable, eg.Shift
	////////////////////////////////////////////////////////////
	void AddKeyboardEvent(int Keycode, int State, int Mod);

	////////////////////////////////////////////////////////////
	/// Adds a window event to the InputManager
	/// --WindowID-- The integer ID of the window that made event.
	/// --Type-- The type of event.
	/// --Data1-- First piece of data associated to event.
	/// --Data2-- Second piece of data associated to event.
	////////////////////////////////////////////////////////////
	void AddWindowEvent(int WindowID, int Type, int Data1, int Data2);

	////////////////////////////////////////////////////////////
	/// Adds a mouse wheel scroll event to the InputManager.
	/// --X-- The X movement of mouse wheel
	/// --Y-- The Y movement of mouse wheel
	/// --Direction-- If Direction of wheel movement is flipped.
	////////////////////////////////////////////////////////////
	void AddMouseScrollEvent(int X, int Y, int Direction);

	////////////////////////////////////////////////////////////
	/// Adds a mouse movement event to the InputManager
	/// --xPos-- The X position of mouse
	/// --yPos-- The Y position of mouse
	/// --xRel-- The Relative X position from previous position.
	/// --yRel-- The Relative Y position from previous position.
	////////////////////////////////////////////////////////////
	void AddMouseMoveEvent(int xPos, int yPos, int xRel, int yRel);

	////////////////////////////////////////////////////////////
	/// Adds a mouse button event to the InputManager
	/// --Button-- The integer number representing the button.
	/// --State-- The current state of button, eg. Pressed or Released.
	/// --Clicks-- The number of clicks, so double or not.
	////////////////////////////////////////////////////////////
	void AddMouseButtonEvent(int Button, int State, int Clicks);

	////////////////////////////////////////////////////////////
	// Member Data
	////////////////////////////////////////////////////////////
	static InputManager _Instance; // Static Instance of InputManager

	bool _CapturedMouse; //Flag to see if Input has captured mouse.

	std::map<int, KeyEvent> KeyboardEvents; // Container of Keyboard Events, accessed with keycodes.
	std::map<int, bool> KeyPressed;			// Container of is key pressed booleans, accessed with keycodes.
	std::map<int, MouseButtonEvent> MouseButtonEvents; // Container of Mouse Button Events, accessed with button codes.
	std::map<int, WindowEvent> WindowEvents; // Container of Window Events, accessed with window event ID's.

	MouseScrollEvent MouseScrollEvt;	// Container for mouse scrolling data.
	MouseMoveEvent MouseMoveEvt;		// Container for mouse movement data.

};

#endif
