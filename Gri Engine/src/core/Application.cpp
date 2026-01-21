#include "Application.h"
#include <chrono>
#include <thread>

namespace GriEngine {

    Application::Application()
        : isRunning(false)
        , timeSinceStart(0.0f) {
        Log::Info("Application constructor");
    }

    Application::~Application() {
        Log::Info("Application destructor");
    }

    void Application::Run() {
        Log::Success("=== Gri Engine Starting ===");

        Initialize();

        isRunning = true;
        timeSinceStart = 0.0f;

        auto lastFrameTime = std::chrono::high_resolution_clock::now();

        Log::Info("Entering main loop...");

        // Главный цикл приложения
        while (isRunning) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            float deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
            lastFrameTime = currentTime;

            timeSinceStart += deltaTime;

            Update(deltaTime);
            Render();

            // Ограничиваем FPS для теста
            std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
        }

        Log::Info("Exiting main loop...");
        Shutdown();

        Log::Success("=== Gri Engine Shutdown ===");
    }

} // namespace GriEngine