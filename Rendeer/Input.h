#pragma once

#include <cstring>
#include <SDL_keyboard.h>

class Display;

class Input
{
public:

	Input()
	{
		memset(isKeyDown, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
		ResetPressedAndReleasedKeys();
	}

	inline bool IsKeyDown(SDL_Scancode key) const { return isKeyDown[key]; }
	inline bool WasKeyPressed(SDL_Scancode key) const { return wasKeyPressed[key]; }
	inline bool WasKeyReleased(SDL_Scancode key) const { return wasKeyReleased[key]; }

private:
	
	// The display keeps track of and polls events, and is therefore
	// responsible for all CHANGES in state of the Input class.
	friend Display;

	// Will reset the arrays wasPressedKeys and wasReleasedKeys to false.
	// The Display class calls this just before polling new events.
	inline void ResetPressedAndReleasedKeys()
	{
		// Set all bytes to false (i.e. 0).
		memset(wasKeyPressed, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
		memset(wasKeyReleased, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
	}

	inline void SetKeyPressed(SDL_Scancode key)
	{
		wasKeyPressed[key] = true;
		isKeyDown[key] = true;
	}

	inline void SetKeyReleased(SDL_Scancode key)
	{
		wasKeyReleased[key] = true;
		isKeyDown[key] = false;
	}




	static const int KEYBOARD_KEY_COUNT = SDL_NUM_SCANCODES;
	bool isKeyDown[KEYBOARD_KEY_COUNT];
	bool wasKeyPressed[KEYBOARD_KEY_COUNT];
	bool wasKeyReleased[KEYBOARD_KEY_COUNT];

};

