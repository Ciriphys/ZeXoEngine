#include "zxpch.h"

#include "Application.h"

#include "Events/KeyEvents.h"
#include "Logger.h"

namespace ZeXo
{ 
	Application::Application(const char * appName) : m_Running(true), m_AppName(appName)
	{
		m_Window = std::unique_ptr<Window>(CreateZeXoWindow(Window::WindowAttributes(appName)));
		m_Window->SetEventCallbackProc(ZX_BIND_FUNCTION(&Application::OnEvent, this));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		ZX_CORE_LOGGER_TRACE("Welcome to ZeXo Engine!");
		while (m_Running)
		{
			m_Window->Tick();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Emit<WindowClosed>(ZX_BIND_FUNCTION(&Application::OnWindowClose, this));
		ZX_CORE_LOGGER_TRACE("[EVENT INFO] {0}", e.GetEventInfo());
	}

	bool Application::OnWindowClose(WindowClosed& e)
	{
		m_Running = false;
		return true;
	}
}