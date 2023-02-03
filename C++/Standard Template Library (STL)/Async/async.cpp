#include <iostream>
#include <future>

int backgroundTask() {
    // Perform a long-running task
    return 42;
}

int main() {
    // Launch the background task asynchronously
    auto result = std::async(backgroundTask);

    // Continue with other tasks while the background task is running
    std::cout << "Doing other things..." << std::endl;

    // Wait for the result of the background task
    int value = result.get();

    // Use the result of the background task
    std::cout << "The result is: " << value << std::endl;

    return 0;
}
