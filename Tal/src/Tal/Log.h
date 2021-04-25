#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Tal 
{
	class TAL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define TAL_CORE_ERROR(...) ::Tal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TAL_CORE_WARN(...) ::Tal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TAL_CORE_INFO(...) ::Tal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TAL_CORE_TRACE(...) ::Tal::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client log macros
#define TAL_CLIENT_ERROR(...) ::Tal::Log::GetClientLogger()->error(__VA_ARGS__)
#define TAL_CLIENT_WARN(...) ::Tal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TAL_CLIENT_INFO(...) ::Tal::Log::GetClientLogger()->info(__VA_ARGS__)
#define TAL_CLIENT_TRACE(...) ::Tal::Log::GetClientLogger()->trace(__VA_ARGS__)

