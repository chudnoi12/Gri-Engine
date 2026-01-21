#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace GriEngine {

    class Log {
    public:
        static void Info(const std::string& message) {
            std::cout << "\033[36m[INFO]\033[0m " << GetTime() << message << std::endl;
        }

        static void Error(const std::string& message) {
            std::cerr << "\033[31m[ERROR]\033[0m " << GetTime() << message << std::endl;
        }

        static void Warn(const std::string& message) {
            std::cout << "\033[33m[WARN]\033[0m " << GetTime() << message << std::endl;
        }

        static void Success(const std::string& message) {
            std::cout << "\033[32m[SUCCESS]\033[0m " << GetTime() << message << std::endl;
        }

    private:
        static std::string GetTime() {
            auto now = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::to_time_t(now);

            // Кроссплатформенное решение
#ifdef _WIN32
    // Безопасная версия для Windows
            struct tm timeInfo;
            localtime_s(&timeInfo, &time);
            char buffer[9];
            strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeInfo);
            return std::string(buffer) + " ";
#else
    // Версия для Linux/Mac
            struct tm* timeInfo = localtime(&time);
            char buffer[9];
            strftime(buffer, sizeof(buffer), "%H:%M:%S", timeInfo);
            return std::string(buffer) + " ";
#endif
        }
    };

} // namespace GriEngine
