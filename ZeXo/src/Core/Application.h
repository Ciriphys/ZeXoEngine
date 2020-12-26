#pragma once

#include "Macro.h"
#include "Layer.h"
#include "Window.h"
#include "Utility.h"
#include "LayerContainer.h"

#include "Events/Event.h"
#include "Events/WindowEvents.h"
#include "Events/KeyEvents.h"

#include "Input/Input.h"

namespace ZeXo
{
	class ZX_API Application
	{
	public: 
		Application(const char * appName = "ZeXo Client");
		~Application();

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		void Run();

		void OnEvent(Event& e);

		inline operator const char* () { return m_AppName; }
		inline void * GetWindowRaw() const { return (void *)&m_Window; }

		void AddLayer		(Layer* layer);
		void AddOverlay		(Layer* overlay);
		void RemoveLayer	(Layer* layer);
		void RemoveOverlay	(Layer* overlay);

		static Application * Get();

	private:
		bool OnWindowResize(WindowResized& e);
		bool OnWindowClose(WindowClosed& e);
		bool OnKeyPress(KeyPressed& e);
		bool OnKeyRelease(KeyReleased& e);

		Unique<Window> m_Window;
		Unique<Input> m_InputHandler;
		Unique<LayerContainer> m_LayerHandler;

		static Application * s_Instance;

		const char* m_AppName;

		double m_LastFrameTime;

		bool m_Running;
		bool m_Minimized;
	};

}