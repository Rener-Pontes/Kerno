#include "logger.hpp"

#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace kerno {

    void Logger::init() {
        spdlog::set_pattern("%^ [%D -- %X] %n (%l) %v %$");

        s_engineLogger = spdlog::stderr_color_mt("ENGINE");
        s_engineLogger->set_level(spdlog::level::trace);

        s_clientLogger = spdlog::stderr_color_mt("CLIENT");
        s_clientLogger->set_level(spdlog::level::trace);
    }

} // namespace kerno
