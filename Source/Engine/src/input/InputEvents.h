#pragma once

#include "../event/Event.h"
#include "Peripherals.h"
#include "InputAction.h"
#include "math/Math.h"
#include "util/String.h"

namespace Quartz
{
	struct RawKeyEvent : public Event<RawKeyEvent>
	{
		Keyboard*		pKeyboard;
		UInt32			key;
		InputAction	action;
	};

	struct RawMouseButtonEvent : public Event<RawMouseButtonEvent>
	{
		Mouse*			pMouse;
		UInt32			button;
		InputAction	action;
	};

	struct RawMouseMoveEvent : public Event<RawMouseMoveEvent>
	{
		Mouse*	pMouse;
		Vector2	relative;
		Vector2 absolute;
	};

	struct InputActionEvent : public Event<InputActionEvent>
	{
		String	name;
		Vector3 axis;
		Float32 value;
	};
}