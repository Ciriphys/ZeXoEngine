#pragma once

#include "Macro.h"
#include "Utility.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>

namespace ZeXo
{
	class ZX_API Logger
	{
	public:
		static void Init();

		inline static Shared<spdlog::logger>& GetCoreLogger()	 {  return s_CoreLogger;  }
		inline static Shared<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static Shared<spdlog::logger> s_CoreLogger;
		static Shared<spdlog::logger> s_ClientLogger;
	};
}

#ifdef ZX_USE_LOGGER

#define ZX_CORE_LOGGER_INFO(...)	::ZeXo::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define ZX_CORE_LOGGER_WARN(...)	::ZeXo::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define ZX_CORE_LOGGER_ERROR(...)	::ZeXo::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define ZX_CORE_LOGGER_TRACE(...)	::ZeXo::Logger::GetCoreLogger()->trace(__VA_ARGS__)

#define ZX_CLIENT_LOGGER_INFO(...)  ::ZeXo::Logger::GetClientLogger()->info(__VA_ARGS__)
#define ZX_CLIENT_LOGGER_WARN(...)  ::ZeXo::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define ZX_CLIENT_LOGGER_ERROR(...) ::ZeXo::Logger::GetClientLogger()->error(__VA_ARGS__)
#define ZX_CLIENT_LOGGER_TRACE(...) ::ZeXo::Logger::GetClientLogger()->trace(__VA_ARGS__)

#else

#define ZX_CORE_LOGGER_INFO(...)  
#define ZX_CORE_LOGGER_WARN(...)  
#define ZX_CORE_LOGGER_ERROR(...) 
#define ZX_CORE_LOGGER_TRACE(...) 

#define ZX_CLIENT_LOGGER_INFO(...)
#define ZX_CLIENT_LOGGER_WARN(...)
#define ZX_CLIENT_LOGGER_ERROR(...)
#define ZX_CLIENT_LOGGER_TRACE(...)

#endif