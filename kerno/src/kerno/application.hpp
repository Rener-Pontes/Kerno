#pragma once

#include "kerno/core.hpp"

namespace kerno {

    class KRN_API Application {
    public:
        Application() = default;
        virtual ~Application() = default;

        virtual int run();
    };

    // User MUST implement this function
    extern Application* createApplication();

} // namespace kerno
