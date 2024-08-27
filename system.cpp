#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

void printSystemMetrics() {
    // Get the current time
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current Time: " << std::ctime(&currentTime);

    // Simulate system uptime by measuring how long the program has been running
    static auto startTime = std::chrono::steady_clock::now();
    auto uptime = std::chrono::steady_clock::now() - startTime;
    auto uptimeInSeconds = std::chrono::duration_cast<std::chrono::seconds>(uptime).count();
    std::cout << "System Uptime: " << uptimeInSeconds << " seconds\n";
}

int main() {
    while (true) {
        printSystemMetrics();
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait for 5 seconds
    }
    return 0;
}
