#pragma once

#include "Core/Macro.h"
#include "Events/Event.h"

struct GLFWwindow;

namespace ZeXo
{

	class ZX_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		struct WindowAttributes
		{
			const char* wndName;
			unsigned int wndWidth;
			unsigned int wndHeight;
			bool wnd_vSync;

			WindowAttributes(const char* name, unsigned int width = 800u, unsigned int height = 600u, bool vSync = true) :
				wndName(name), wndWidth(width), wndHeight(height), wnd_vSync(vSync) {}
		};

		Window(const WindowAttributes& wndAttrib = WindowAttributes("ZeXo Client")) : m_Data(wndAttrib) {}
		virtual ~Window() {}

		WindowAttributes& GetWindowData() { return m_Data; }

		inline const char* GetWindowTitle() const { return m_Data.wndName; }
		inline unsigned int GetWidth()  const { return m_Data.wndWidth;  }
		inline unsigned int GetHeight() const { return m_Data.wndHeight; }
		inline bool IsVsync() const { return m_Data.wnd_vSync; }

		virtual void SetEventCallbackProc(const EventCallbackFunction& cbfn) = 0;

		virtual void Init() = 0;
		virtual void Tick() = 0;
		virtual void Exit() const = 0;
		virtual void SetVsync(bool shouldVsync) = 0;

		virtual GLFWwindow* glfwGetWindow() const = 0;

	private:
		WindowAttributes m_Data;
	};

	Window * CreateZeXoWindow(const Window::WindowAttributes& wndAttrib = Window::WindowAttributes("ZeXo Client"));
}