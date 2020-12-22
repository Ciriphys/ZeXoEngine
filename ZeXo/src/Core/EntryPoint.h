#pragma once

#ifdef ZX_PLAT_WIN

#include "Logger.h"

extern ZeXo::Application* CreateZeXoApplication();

int main(int argc, char** argv)
{
	ZeXo::Logger::Init();

	auto app = CreateZeXoApplication();
	app->Run();
	delete app;
}

#endif