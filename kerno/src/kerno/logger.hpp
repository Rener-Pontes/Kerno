#pragma once

#include "core.hpp"

#include <spdlog/spdlog.h>

namespace kerno {

    class KRN_API Logger {
    public:
        Logger() = delete;
        ~Logger() = delete;

        static void init();

        inline static std::shared_ptr<spdlog::logger>& engineLogger() { return s_engineLogger; }
        inline static std::shared_ptr<spdlog::logger>& clientLogger() { return s_clientLogger; }

    private:
        inline static std::shared_ptr<spdlog::logger> s_engineLogger;
        inline static std::shared_ptr<spdlog::logger> s_clientLogger;
    };

} // namespace kerno

#ifdef KRN_DEBUG

    #define KRN_ENGINE_DEBUG(...) ::kerno::Logger::engineLogger()->debug(__VA_ARGS__)
    #define KRN_ENGINE_TRACE(...) ::kerno::Logger::engineLogger()->trace(__VA_ARGS__)
    #define KRN_ENGINE_INFO(...) ::kerno::Logger::engineLogger()->info(__VA_ARGS__)
    #define KRN_ENGINE_WARN(...) ::kerno::Logger::engineLogger()->warn(__VA_ARGS__)
    #define KRN_ENGINE_ERROR(...) ::kerno::Logger::engineLogger()->error(__VA_ARGS__)
    #define KRN_ENGINE_CRITICAL(...) ::kerno::Logger::engineLogger()->critical(__VA_ARGS__)

    #define KRN_CLIENT_DEBUG(...) ::kerno::Logger::engineLogger()->debug(__VA_ARGS__)
    #define KRN_CLIENT_TRACE(...) ::kerno::Logger::engineLogger()->trace(__VA_ARGS__)
    #define KRN_CLIENT_INFO(...) ::kerno::Logger::engineLogger()->info(__VA_ARGS__)
    #define KRN_CLIENT_WARN(...) ::kerno::Logger::engineLogger()->warn(__VA_ARGS__)
    #define KRN_CLIENT_ERROR(...) ::kerno::Logger::engineLogger()->error(__VA_ARGS__)
    #define KRN_CLIENT_CRITICAL(...) ::kerno::Logger::engineLogger()->critical(__VA_ARGS__)

    // RelWithDebInfo doesn't need this loggers
    #ifdef KRN_RELEASE

        #define KRN_ENGINE_DEBUG(...)
        #define KRN_ENGINE_TRACE(...)

        #define KRN_CLIENT_DEBUG(...)
        #define KRN_CLIENT_TRACE(...)

    #endif // !KRN_RELEASE

#else

    #define KRN_ENGINE_DEBUG(...)
    #define KRN_ENGINE_TRACE(...)
    #define KRN_ENGINE_INFO(...)
    #define KRN_ENGINE_WARN(...)
    #define KRN_ENGINE_ERROR(...)
    #define KRN_ENGINE_CRITICAL(...)

    #define KRN_CLIENT_DEBUG(...)
    #define KRN_CLIENT_TRACE(...)
    #define KRN_CLIENT_INFO(...)
    #define KRN_CLIENT_WARN(...)
    #define KRN_CLIENT_ERROR(...)
    #define KRN_CLIENT_CRITICAL(...)

#endif // KRN_DEBUG
