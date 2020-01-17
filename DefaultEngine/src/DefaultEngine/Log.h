#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"



namespace DefaultEngine {

	class DefaultEngine_API Log
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

// Core log macros
#define DE_CORE_TRACE(...)    ::DefaultEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DE_CORE_INFO(...)     ::DefaultEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DE_CORE_WARN(...)     ::DefaultEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DE_CORE_ERROR(...)    ::DefaultEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DE_CORE_FATAL(...)    ::DefaultEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DE_TRACE(...)	      ::DefaultEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DE_INFO(...)	      ::DefaultEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define DE_WARN(...)	      ::DefaultEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DE_ERROR(...)	      ::DefaultEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define DE_FATAL(...)	      ::DefaultEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)