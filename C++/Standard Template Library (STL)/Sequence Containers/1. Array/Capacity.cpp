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

    // Assigns the value to all elements in the container.
    void Fill()
    {
        constexpr size_t xy = 4;

        using Cell = array<unsigned char, 8>;

        array<Cell, xy * xy> board;

        board.fill({{0xE2, 0x96, 0x84, 0xE2, 0x96, 0x80, 0, 0}}); // "▄▀";

        for (size_t count{}; Cell c : board)
        {
            cout << c.data() << ((++count % xy) ? "" : "\n");
        }

        // Possible output:
        // ▄▀▄▀▄▀▄▀
        // ▄▀▄▀▄▀▄▀
        // ▄▀▄▀▄▀▄▀
        // ▄▀▄▀▄▀▄▀
    }

    // Exchanges the contents of the container with those of other.
    // Does not cause iterators and references to associate with the other container.
    void Swap()
    {
        array<int, 3> a1{1, 2, 3}, a2{4, 5, 6};

        auto it1 = a1.begin();
        auto it2 = a2.begin();
        int &ref1 = a1[1];
        int &ref2 = a2[1];
        cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
        a1.swap(a2);
        cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
        // Note that after swap iterators and references stay associated with their original
        // array, e.g. `it1` still points to element a1[0], `ref1` still refers to a1[1].

        // Output:
        // { 1 2 3 } { 4 5 6 } 1 4 2 5
        // { 4 5 6 } { 1 2 3 } 4 1 5 2
    }
};

int main()
{
    MyCapacity myarray;

    return 0;
}
