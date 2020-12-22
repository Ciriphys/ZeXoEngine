#pragma once

#include "Core/Macro.h"

#include <string>
#include <functional>

namespace ZeXo
{
	enum class EventType
	{
		KeyPressed,
		KeyReleased,

		MouseMoved,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseWheelScrolled, 

		WindowResized,
		WindowClosed,

		AppTick,
		AppRender,
	};

	class ZX_API Event
	{
	protected:
		bool m_Handled = false;

		friend class EventDispatcher;

	public:
		virtual ~Event() {}

		virtual EventType	GetEventType()		const = 0;
		virtual const char* GetEventName()		const = 0;
		virtual std::string GetEventNameStr()   const = 0;
		virtual std::string GetEventInfo()		const = 0;

		virtual bool IsHandled() const = 0;
	};

	class EventDispatcher
	{
	private:
		template <typename T>
		using EventFunction = std::function<bool(const T&)>;

		Event& m_Event;
	public:
		EventDispatcher(Event& e) : m_Event(e) {}

		template <typename T>
		bool Dispatch(EventFunction<T> function)
		{
			if (m_Event.GetEventType() == T::GetEventStaticType())
			{
				m_Event.m_Handled = function(*(T*)&m_Event);
				return true;
			}

			return false;
		}
	};
}