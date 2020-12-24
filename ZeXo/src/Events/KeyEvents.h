#pragma once

#include "zxpch.h"

#include "Core/Macro.h"
#include "Event.h"

namespace ZeXo
{
	class ZX_API KeyEvent : public Event
	{
	protected:
		int m_Keycode;
		KeyEvent(int keycode) : m_Keycode(keycode) {}
	public:
		inline int GetKeyCode() const { return m_Keycode; }
	};

	class ZX_API KeyPressed : public KeyEvent
	{
	public:
		KeyPressed(int keycode, int count) : KeyEvent(keycode), m_Count(count) {}

		inline int GetCount() const { return m_Count; }

		virtual EventType	GetEventType()		const override { return EventType::KeyPressed; }
		virtual const char* GetEventName()		const override { return "KeyPressed"; }
		virtual std::string GetEventNameStr()	const override { return "KeyPressed"; }
		virtual bool		IsHandled()			const override { return m_Handled; }

		virtual std::string GetEventInfo() const override 
		{
			std::stringstream ss;
			ss << "KeyPressed: [Keycode(" << m_Keycode << ") | Repetitions(" << m_Count << ")]";
			return ss.str();
		}

		static EventType GetEventStaticType() { return EventType::KeyPressed; }

	private:
		int m_Count;
	};

	class ZX_API KeyReleased : public KeyEvent
	{
	public:
		KeyReleased(int keycode) : KeyEvent(keycode) {}

		virtual EventType   GetEventType()		const override { return EventType::KeyReleased; }
		virtual const char* GetEventName()		const override { return "KeyReleased"; }
		virtual std::string GetEventNameStr()	const override { return "KeyReleased"; }
		virtual bool		IsHandled()			const override { return m_Handled; }

		virtual std::string GetEventInfo() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: [Keycode(" << m_Keycode << ")]";
			return ss.str();
		}

		static EventType GetEventStaticType() { return EventType::KeyReleased; }
	};
}