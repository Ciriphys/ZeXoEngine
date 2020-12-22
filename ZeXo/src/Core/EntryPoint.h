#pragma once

#ifdef ZX_PLAT_WIN

#include "Application.h"

extern ZeXo::Application* CreateZeXoApplication();

int main(int argc, char** argv)
{
	auto app = CreateZeXoApplication();
	app->Run();
	delete app;
}

#endif