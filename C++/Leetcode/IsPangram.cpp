// Write a function called IsPangram which returns true if every single lower-cased letter of the English alphabet is used. 
// Every character in the string will be lowercase so you do not need to worry about upper and lower case.

#include <iostream>
#include <string>
#include <unordered_set>

bool IsPangram(const std::string& str) {
    std::unordered_set<char> letters;

    for (const char& ch : str) {
        if (isalpha(ch)) {
            letters.insert(ch);
        }
    }

    return letters.size() == 26;
}

int main() {
    std::string str = "the quick brown fox jumps over the lazy dog";
    bool isPangram = IsPangram(str);
    std::cout << std::boolalpha << isPangram << std::endl;  // Output: true

    str = "hello world";
    isPangram = IsPangram(str);
    std::cout << std::boolalpha << isPangram << std::endl;  // Output: false

    return 0;
}