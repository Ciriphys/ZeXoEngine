#pragma once

#include "Macro.h"

#include "Events/Event.h"
#include "Events/WindowEvents.h"
#include "Events/KeyEvents.h"

#include "Input/Input.h"

#include "Window.h"

namespace ZeXo
{
	class ZX_API Application
	{
	public: 
		Application(const char * appName = "ZeXo Client");
		~Application();

		void Run();

		void OnEvent(Event& e);

		inline operator const char* () { return m_AppName; }
		inline void * GetWindowRaw() const { return (void *)&m_Window; }

		static Application * Get();

	private:
		bool OnWindowClose(WindowClosed& e);
		bool OnKeyPress(KeyPressed& e);
		bool OnKeyRelease(KeyReleased& e);

		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Input> m_InputHandler;

		static Application * s_Instance;

		const char* m_AppName;
		bool m_Running;
	};

}