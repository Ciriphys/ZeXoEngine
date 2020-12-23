#include "zxpch.h"

#include "Application.h"

#include "Events/KeyEvents.h"
#include "Logger.h"

namespace ZeXo
{ 
	Application::Application() : m_Running(true)
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		KeyPressed keyPress = KeyPressed(52, 19);
		ZX_CORE_LOGGER_TRACE("Welcome to ZeXo Engine!");
		ZX_CLIENT_LOGGER_INFO(keyPress.GetEventInfo());
		while (m_Running);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Emit<WindowClosed>(ZX_BIND_MEMBER_FUNCTION(this, &Application::OnWindowClose));
	}

	bool Application::OnWindowClose(WindowClosed& e)
	{
		m_Running = false;
		return true;
	}
}