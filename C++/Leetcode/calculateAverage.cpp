// Write a function called calculateAverage which accepts an array of numbers. 
// The function should return the average or mean of all number in the array. If the array is empty return 0.

#include <iostream>
#include <vector>

double CAV(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    double total = 0;
    for (const double& number : numbers) {
        total += number;
    }

    return total / numbers.size();
}


int main() {
    std::vector<double> numbers = {1, 2, 3, 4, 5};
    double average = CAV(numbers);
    std::cout << average << std::endl;  // Output: 3

    std::vector<double> empty_array;
    average = CAV(empty_array);
    std::cout << average << std::endl;  // Output: 0

    return 0;
}