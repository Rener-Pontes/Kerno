#pragma once

extern kerno::Application* kerno::createApplication();

int main() {
    kerno::Logger::init();

    KRN_CLIENT_INFO("Application started!");

    auto app = kerno::createApplication();
    int result = app->run();

    delete app;
    return result;
}
