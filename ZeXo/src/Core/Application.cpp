#include "Application.h"

#include "Events/KeyEvents.h"
#include "Logger.h"

namespace ZeXo
{ 
	Application::Application()
	{
	}

	void Application::Run()
	{
		KeyPressed keyPress = KeyPressed(52, 0);
		ZX_CORE_LOGGER_TRACE("Welcome to ZeXo Engine!");
		ZX_CORE_LOGGER_INFO(keyPress.GetEventInfo());
		while (true);
	}

}