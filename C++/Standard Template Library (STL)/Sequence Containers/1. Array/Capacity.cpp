#include <cstddef>
#include <iostream>
#include <array>
#include <span>

using namespace std;
class MyCapacity
{

public:
    // Checks if the container has no elements, i.e. whether begin() == end().
    void Empty()
    {
        array<int, 4> numbers{3, 1, 4, 1};
        array<int, 0> no_numbers;
        cout << boolalpha;
        cout << "numbers.empty(): " << numbers.empty() << '\n';
        cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';

        // Output:
        // numbers.empty(): false
        // no_numbers.empty(): true
    }

    // Returns the number of elements in the container, i.e. distance(begin(), end()).
    void Size()
    {
        array<int, 4> nums{1, 3, 5, 7};
        cout << "nums contains " << nums.size() << " elements.\n";

        // Output:
        // nums contains 4 elements.
    }

    // Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e.
    // distance(begin(), end()) for the largest container.
    void MaxSize()
    {
        array<char, 10> q;
        cout.imbue(locale("en_US.UTF-8"));
        cout << "Maximum size of the array is " << q.max_size() << '\n';
    }
};

int main()
{
    MyCapacity myarray;

    return 0;
}
