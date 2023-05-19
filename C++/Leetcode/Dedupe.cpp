// Write a C++ function called dedupe which accepts an array of intergers and returns a new array with all duplicates removed. 
// For example, if an array looked like this [5,5,5,2,2] and was passed into dedupe, it should return this array [5,2].
#include <vector>
#include <unordered_set>
#include <iostream>

std::vector<int> dedupe(const std::vector<int>& numbers) {
    std::unordered_set<int> uniqueNumbers;
    std::vector<int> result;

    for (const int& number : numbers) {
        if (uniqueNumbers.find(number) == uniqueNumbers.end()) {
            uniqueNumbers.insert(number);
            result.push_back(number);
        }
    }

    return result;
}

int main() {
    std::vector<int> numbers = {5, 5, 5, 2, 2};
    std::vector<int> result = dedupe(numbers);

    for (const int& number : result) {
        std::cout << number << " ";
    }
    std::cout << std::endl;  // Output: 5 2

    return 0;
}
