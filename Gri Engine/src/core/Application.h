#pragma once

#include "../utils/Log.h"

namespace GriEngine {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
        virtual void Initialize() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Render() = 0;
        virtual void Shutdown() = 0;

        bool IsRunning() const { return isRunning; }
        void RequestClose() { isRunning = false; }

    protected:
        bool isRunning;
        float timeSinceStart;
    };

} // namespace GriEngine