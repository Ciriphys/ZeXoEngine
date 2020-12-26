#include "zxpch.h"

#include "Application.h"

#include "Logger.h"
#include "Time.h"

namespace ZeXo
{ 
#define COMPUTE_TIME double currentFrame = m_Window->GetWindowTime();\
	Time timeHandler = currentFrame - m_LastFrameTime;\
	m_LastFrameTime = currentFrame;

	Application * Application::s_Instance = nullptr;

	Application::Application(const char * appName) : m_Running(true), m_Minimized(false), m_AppName(appName), m_LastFrameTime(0.0)
	{
		ZX_ASSERT(!s_Instance, "Another instance of Application exists!");
		s_Instance = this;

		m_Window = CreateUnique<Window>(CreateZeXoWindow(Window::WindowAttributes(appName)));
		m_Window->SetEventCallbackProc(ZX_BIND_FUNCTION(&Application::OnEvent, this));

		m_InputHandler = CreateUnique<Input>(Input::Get());
		m_LayerHandler = CreateUnique<LayerContainer>(LayerContainer::Get());
	}

	Application::~Application()
	{
		m_Window->Exit();
	}

	void Application::Run()
	{
		ZX_CORE_LOGGER_TRACE("Welcome to ZeXo Engine!");
		while (m_Running)
		{
			COMPUTE_TIME;
			m_Window->Tick();

			if (!m_Minimized)
			{
				for (auto& layer : *m_LayerHandler)
				{
					layer->Tick(timeHandler.GetDeltaTime());
				}
			}
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Emit<WindowClosed>(ZX_BIND_FUNCTION(&Application::OnWindowClose, this));
		dispatcher.Emit<WindowResized>(ZX_BIND_FUNCTION(&Application::OnWindowResize, this));
		//dispatcher.Emit<KeyPressed>(ZX_BIND_FUNCTION(&Application::OnKeyPress, this));
		//dispatcher.Emit<KeyReleased>(ZX_BIND_FUNCTION(&Application::OnKeyRelease, this));

		for (auto it = m_LayerHandler->rbegin(); it != m_LayerHandler->rend(); ++it)
		{
			(*it)->Event(e);
			if (e)
				break;
		}

	}

	void Application::AddLayer(Layer* layer)
	{
		m_LayerHandler->AddLayer(layer);
	}

	void Application::AddOverlay(Layer* overlay)
	{
		m_LayerHandler->AddOverlay(overlay);
	}

	void Application::RemoveLayer(Layer* layer)
	{
		m_LayerHandler->RemoveLayer(layer);
	}

	void Application::RemoveOverlay(Layer* overlay)
	{
		m_LayerHandler->RemoveOverlay(overlay);
	}

	Application * Application::Get()
	{
		return s_Instance;
	}

	bool Application::OnWindowResize(WindowResized& e)
	{
		if (e.GetWidth() == 0 && e.GetHeigth() == 0)
		{
			m_Minimized = true;
		}
		else
		{
			m_Minimized = false;
		}

		return true;
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