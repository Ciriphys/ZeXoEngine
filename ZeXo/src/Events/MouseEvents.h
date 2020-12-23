#pragma once

#include "zxpch.h"

#include "Core/Macro.h"
#include "Event.h"

namespace ZeXo
{
	class ZX_API MouseButtonPressed : public Event
	{
	public:
		MouseButtonPressed(int button) : m_Button(button) {}

		virtual EventType	GetEventType()		const { return EventType::MouseButtonPressed; }
		virtual const char* GetEventName()		const { return "MouseButtonPressed"; }
		virtual std::string GetEventNameStr()   const { return "MouseButtonPressed"; }

		virtual std::string GetEventInfo() const {
			std::stringstream ss;
			ss << "MouseButtonPressed: [Button(" << m_Button << ")]";
			return ss.str();
		}

		virtual bool IsHandled() const { return m_Handled; }
		static EventType GetEventStaticType() { return EventType::MouseButtonPressed; }

	private:
		int m_Button;
	};

	class ZX_API MouseButtonReleased : public Event
	{
	public:
		MouseButtonReleased(int button) : m_Button(button) {}

		virtual EventType	GetEventType()		const { return EventType::MouseButtonReleased; }
		virtual const char* GetEventName()		const { return "MouseButtonReleased"; }
		virtual std::string GetEventNameStr()   const { return "MouseButtonReleased"; }

		virtual std::string GetEventInfo() const {
			std::stringstream ss;
			ss << "MouseButtonReleased: [Button(" << m_Button << ")]";
			return ss.str();
		}

		virtual bool IsHandled() const { return m_Handled; }
		static EventType GetEventStaticType() { return EventType::MouseButtonReleased; }

	private:
		int m_Button;
	};

	class ZX_API MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y) : m_X(x), m_Y(y) {}

		virtual EventType	GetEventType()		const { return EventType::MouseMoved; }
		virtual const char* GetEventName()		const { return "MouseMoved"; }
		virtual std::string GetEventNameStr()   const { return "MouseMoved"; }

		float GetHorizontalPosition() const { return m_X; }
		float GetVerticalPosition()	  const { return m_Y; }

		virtual std::string GetEventInfo() const {
			std::stringstream ss;
			ss << "MouseMoved: [x(" << m_X << ") | y(" << m_Y << ")]";
			return ss.str();
		}

		virtual bool IsHandled() const { return m_Handled; }
		static EventType GetEventStaticType() { return EventType::MouseMoved; }

	private:
		float m_X;
		float m_Y;
	};

	class MouseWheelScrolled : public Event
	{
	public: 
		MouseWheelScrolled(float xoff, float yoff) : m_Wheel_xOffset(xoff), m_Wheel_yOffset(yoff) {}

		virtual EventType	GetEventType()		const { return EventType::MouseWheelScrolled; }
		virtual const char* GetEventName()		const { return "MouseWheelScrolled"; }
		virtual std::string GetEventNameStr()   const { return "MouseWheelScrolled"; }

		float GetHorizontalOffset() const { return m_Wheel_xOffset; }
		float GetVerticalOffset()	const { return m_Wheel_yOffset; }

		virtual std::string GetEventInfo() const {
			std::stringstream ss;
			ss << "MouseWheelScrolled: [x(" << m_Wheel_xOffset << ") | y(" << m_Wheel_yOffset << ")]";
			return ss.str();
		}

		virtual bool IsHandled() const { return m_Handled; }
		static EventType GetEventStaticType() { return EventType::MouseButtonReleased; }

	private:
		float m_Wheel_xOffset;
		float m_Wheel_yOffset;
	};
}