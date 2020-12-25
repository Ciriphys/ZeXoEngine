#pragma once

#ifdef ZX_PLAT_WIN

#include "Core/Macro.h"
#include "Core/Window.h"

#include <GLFW/glfw3.h>

namespace ZeXo
{
	class ZX_API WinWindow : public Window
	{
	public:
		 WinWindow(const Window::WindowAttributes& wndAttrib);
		~WinWindow();

		virtual void Init() override;
		virtual void Tick() override;
		virtual void Shutdown() const override;
		virtual void SetEventCallbackProc(const EventCallbackFunction& cbfn) override;

		virtual GLFWwindow * glfwGetWindow() const override { return m_Window; };

	private:
		GLFWwindow * m_Window;
		EventCallbackFunction m_CallbackFn;
	};

}

#endif