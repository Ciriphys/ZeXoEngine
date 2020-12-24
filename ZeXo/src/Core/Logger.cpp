#include "zxpch.h"

#include "Logger.h"

namespace ZeXo
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] { %n } %v%$");

		s_CoreLogger	= spdlog::stdout_color_mt("ZeXo Engine");
		s_ClientLogger  = spdlog::stdout_color_mt("Client"); // Todo : Use Application Name

		s_CoreLogger->set_level(spdlog::level::level_enum::trace);
		s_ClientLogger->set_level(spdlog::level::level_enum::trace);
	}
}