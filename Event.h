#pragma once
#include "Keyboard.h"

class Event
{
public:
	struct KeyEvent
	{
		Keyboard Keycode;
		bool alt;
		bool control;
		bool shift;
		bool system;
	};

	enum EventType
	{
		KeyPressed,
		KeyReleased,

		Count
	};

	EventType type;

	union
	{
		KeyEvent key;
	};
};