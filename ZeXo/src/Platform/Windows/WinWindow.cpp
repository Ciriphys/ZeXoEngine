#include "zxpch.h"

#ifdef ZX_PLAT_WIN

#include "winWindow.h"

#include "Events/Event.h"	
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Events/WindowEvents.h"

#include "Core/Logger.h"

namespace ZeXo
{
	static bool s_Init = false;
	static int s_KeyCount = 0;

	Window * CreateZeXoWindow(const Window::WindowAttributes& wndAttrib)
	{
		return new WinWindow(wndAttrib);
	}

	WinWindow::WinWindow(const Window::WindowAttributes& wndAttrib) : Window(wndAttrib)
	{
		Init();
	}

	WinWindow::~WinWindow()
	{
		Exit();
	}

	void WinWindow::Init()
	{
		Window::WindowAttributes& data = GetWindowData();
		
		if (!s_Init)
		{
			ZX_ASSERT(glfwInit(), "GLFW initialization didn't succed!");
			s_Init = true;		
		}

		m_Window = glfwCreateWindow(data.wndWidth, data.wndHeight, data.wndName, nullptr, nullptr);
		ZX_ASSERT(m_Window, "Couldn't create window!");

		ZX_CORE_LOGGER_INFO("Created window {0} [{1}, {2}]", data.wndName, data.wndWidth, data.wndHeight);

		glfwMakeContextCurrent(m_Window);
		ZX_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Could not initialize Glad!");
		glfwSetWindowUserPointer(m_Window, &m_CallbackFn);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			EventCallbackFunction& cbfn = *(EventCallbackFunction*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressed e(key, s_KeyCount);
					cbfn(e);
					break;
				}
			case GLFW_RELEASE:
				{
					s_KeyCount = 0;
					KeyReleased e(key);
					cbfn(e);
					break;
				}
			case GLFW_REPEAT:
				{
					s_KeyCount++;
					KeyPressed e(key, s_KeyCount);
					cbfn(e);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			EventCallbackFunction& cbfn = *(EventCallbackFunction*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressed mouseButtonPressed = MouseButtonPressed(button);
					cbfn(mouseButtonPressed);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleased mouseButtonPressed = MouseButtonReleased(button);
					cbfn(mouseButtonPressed);
					break;
				}
			}
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)	{
			EventCallbackFunction& cbfn = *(EventCallbackFunction*)glfwGetWindowUserPointer(window);

			MouseMoved mouseMoved = MouseMoved((float)xpos, (float)ypos);
			cbfn(mouseMoved);
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			EventCallbackFunction& cbfn = *(EventCallbackFunction*)glfwGetWindowUserPointer(window);

			MouseWheelScrolled mouseMoved = MouseWheelScrolled((float)xpos, (float)ypos);
			cbfn(mouseMoved);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			EventCallbackFunction& cbfn = *(EventCallbackFunction*)glfwGetWindowUserPointer(window);

			WindowResized windowResized = WindowResized(width, height);
			cbfn(windowResized);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			EventCallbackFunction& cbfn = *(EventCallbackFunction*)glfwGetWindowUserPointer(window);

			WindowClosed windowClosed = WindowClosed();
			cbfn(windowClosed);
		});
	}

	void WinWindow::Tick()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WinWindow::Exit() const
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void WinWindow::SetVsync(bool shouldVsync)
	{
		glfwSwapInterval(shouldVsync);
	}

	double WinWindow::GetWindowTime() const
	{
		return glfwGetTime();
	}

	void WinWindow::SetEventCallbackProc(const EventCallbackFunction& cbfn)
	{
		m_CallbackFn = cbfn;
	}

}

#endif