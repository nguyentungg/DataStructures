// Write a function called strExpand which accepts string of where letters are all grouped together (like aaee or bbccdd) and returns a new sting with each letter fowllowed by a count of a the number of time it appears. 
// For instance, given the input "aaee" you would return "a2e2"
#include <iostream>
#include <string>
#include <sstream>

std::string strExpand(const std::string& str) {
    std::string expandedStr;
    int count = 1;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            expandedStr += str[i] + std::to_string(count);
            count = 1;
        }
    }

    return expandedStr;
}

int main() {
    std::string input = "aaee";
    std::string expandedString = strExpand(input);
    std::cout << expandedString << std::endl;  // Output: "a2e2"

    std::string input2 = "bbccdd";
    std::string expandedString2 = strExpand(input2);
    std::cout << expandedString2 << std::endl;  // Output: "b2c2d2"

    return 0;
}
