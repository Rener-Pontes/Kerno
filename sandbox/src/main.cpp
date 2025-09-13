#include <iostream>

#include <kerno.hpp>

class SandboxApp : public kerno::Application {
public:
    SandboxApp() = default;
    virtual ~SandboxApp() = default;

    virtual int run() {
        std::cout << "Running from sandbox!" << std::endl;
        return 0;
    }
};

kerno::Application* kerno::createApplication() {
    return new SandboxApp();
}
