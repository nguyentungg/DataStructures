#include <array>
#include <cstddef>
#include <iostream>

using namespace std;
class MyOperations
{
public:

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
    MyOperations myarray;
    myarray.Fill();
    return 0;
}
