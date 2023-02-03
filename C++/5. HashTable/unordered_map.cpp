#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> hash_table;

  // Insert key-value pairs
  hash_table["one"] = 1;
  hash_table["two"] = 2;
  hash_table["three"] = 3;

  // Access values by key
  std::cout << hash_table["one"] << std::endl;
  std::cout << hash_table["two"] << std::endl;
  std::cout << hash_table["three"] << std::endl;

  return 0;
}
