#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

// Function to display real-time clock
void displayRealTimeClock() {
    while (true) {
        // Get the current time
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);

        // Convert to local time
        std::tm now_local;
        localtime_s(&now_local, &now_time_t); // Use localtime_s for thread safety

        // Print the time, overwriting the previous one
        std::cout << "\r" << std::put_time(&now_local, "%H:%M:%S") << std::flush;

        // Wait for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Main function
void waktu() {
    displayRealTimeClock();
    // No return needed
}