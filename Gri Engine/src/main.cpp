#include "core/Application.h"
#include "utils/Log.h"
#include <cmath>

// Простой тестовый класс для проверки
class TestApp : public GriEngine::Application {
public:
    void Initialize() override {
        GriEngine::Log::Success("TestApp initialized!");
        GriEngine::Log::Info("Press Ctrl+C to exit");

        frameCount = 0;
    }

    void Update(float deltaTime) override {
        frameCount++;

        // Простая логика - закрыть через 5 секунд
        if (timeSinceStart > 5.0f) {
            RequestClose();
            GriEngine::Log::Warn("5 seconds elapsed, closing...");
        }

        // Каждую секунду выводим FPS
        if (timeSinceStart > lastFPSTime + 1.0f) {
            float fps = frameCount / (timeSinceStart - lastFPSTime);
            GriEngine::Log::Info("FPS: " + std::to_string(fps));
            lastFPSTime = timeSinceStart;
            frameCount = 0;
        }
    }

    void Render() override {
        // Пока просто симуляция рендера
        // Позже добавим OpenGL
        if (static_cast<int>(timeSinceStart * 2) % 2 == 0) {
            // Имитация работы
        }
    }

    void Shutdown() override {
        GriEngine::Log::Success("TestApp shutdown complete");
    }

private:
    int frameCount;
    float lastFPSTime = 0.0f;
};

int main() {
    GriEngine::Log::Info("=== Gri Engine Launched ===");
    GriEngine::Log::Info("Build: " + std::string(__DATE__) + " " + std::string(__TIME__));

    try {
        TestApp app;
        app.Run();
    }
    catch (const std::exception& e) {
        GriEngine::Log::Error("Exception caught: " + std::string(e.what()));
        return 1;
    }

    return 0;
}