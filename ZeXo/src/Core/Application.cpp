#include "zxpch.h"

#include "Application.h"

#include "Logger.h"

namespace ZeXo
{ 
	Application * Application::s_Instance = nullptr;

	Application::Application(const char * appName) : m_Running(true), m_AppName(appName)
	{
		ZX_ASSERT(!s_Instance, "Another instance of Application exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(CreateZeXoWindow(Window::WindowAttributes(appName)));
		m_Window->SetEventCallbackProc(ZX_BIND_FUNCTION(&Application::OnEvent, this));

		m_InputHandler = std::unique_ptr<Input>(Input::Get());
	}

	Application::~Application()
	{
		m_Window->Shutdown();
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
		dispatcher.Emit<KeyPressed>(ZX_BIND_FUNCTION(&Application::OnKeyPress, this));
		dispatcher.Emit<KeyReleased>(ZX_BIND_FUNCTION(&Application::OnKeyRelease, this));
	}

	Application * Application::Get()
	{
		return s_Instance;
	}

	bool Application::OnWindowClose(WindowClosed& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnKeyPress(KeyPressed& e)
	{
		ZX_CORE_LOGGER_TRACE("{0} key has been pressed.", m_InputHandler->GetKeyName(e.GetKeyCode()));
		return true;
	}

	bool Application::OnKeyRelease(KeyReleased& e)
	{
		ZX_CORE_LOGGER_TRACE("{0} key has been released.", m_InputHandler->GetKeyName(e.GetKeyCode()));
		return true;
	}
}