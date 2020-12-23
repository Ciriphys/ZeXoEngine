#pragma once

#include "Macro.h"

#include "Events/Event.h"
#include "Events/WindowEvents.h"

namespace ZeXo
{
	class ZX_API Application
	{
	public: 
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowClosed& e);

		bool m_Running;
	};

}