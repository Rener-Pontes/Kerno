#pragma once

extern kerno::Application* kerno::createApplication();

int main() {
    auto app = kerno::createApplication();
    int result = app->run();

    delete app;
    return result;
}
