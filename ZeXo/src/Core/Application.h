#pragma once

#include "Macro.h"

#include "Events/Event.h"
#include "Events/WindowEvents.h"
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

	private:
		bool OnWindowClose(WindowClosed& e);

		std::unique_ptr<Window> m_Window;

		const char* m_AppName;
		bool m_Running;
	};

}