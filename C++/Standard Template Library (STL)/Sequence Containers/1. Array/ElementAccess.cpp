#include <cstddef>
#include <iostream>
#include <array>
#include <span>

using namespace std;
class MyElementAccess
{

public:
    // Returns a reference to the element at specified location pos, with bounds checking.
    void At()
    {
        array<int, 6> data = {1, 2, 4, 5, 5, 6};
        // Set element 1
        data.at(1) = 88;
        // Read element 2
        cout << "Element at index 2 has value " << data.at(2) << '\n';
        cout << "data size = " << data.size() << '\n';

        // Try replace non-exit index
        try
        {
            // Set element 6
            data.at(6) = 666;
        }
        catch (out_of_range const &exc)
        {
            cout << exc.what() << '\n';
        }
        // Print final values
        cout << "data:";
        for (int elem : data)
            cout << " " << elem;
        cout << '\n';

        //  Output:
        //  Element at index 2 has value 4
        //  data size = 6
        //  array::at: __n (which is 6) >= _Nm (which is 6)
        //  data: 1 88 4 5 5 6
    }

    // Returns a reference to the element at specified location pos. No bounds checking is performed.
    void Operator()
    {
        array<int, 4> numbers{2, 4, 6, 8};
        cout << "Second element: " << numbers[1] << '\n';
        numbers[0] = 5;
        cout << "All numbers:";
        for (auto i : numbers)
        {
            cout << ' ' << i;
        }
        cout << '\n';

        // Output:
        // Second element: 4
        // All numbers: 5 4 6 8
    }

    // Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    void Front()
    {
        array<char, 6> letters{'o', 'm', 'g', 'w', 't', 'f'};
        if (!letters.empty())
        {
            cout << "The first character is '" << letters.front() << "'.\n";
        }
        // Output:
        // The first character is 'o'.
    }

    // Returns a reference to the last element in the container.
    // Calling back on an empty container causes undefined behavior.
    void Back()
    {
        array<char, 6> letters{'a', 'b', 'c', 'd', 'e', 'f'};
        if (!letters.empty())
        {
            cout << "The last character is '" << letters.back() << "'.\n";
        }
        // Output:
        // The last character is 'f'.
    }

    // Returns pointer to the underlying array serving as element storage.
    // The pointer is such that range [data(); data()+size()) is always a valid range, even if the container is empty (data() is not dereferenceable in that case).
    void pointer_func(const int *p, std::size_t size)
    {
        cout << "data = ";
        for (size_t i = 0; i < size; ++i)
            cout << p[i] << ' ';
        cout << '\n';
    }
    void span_func(span<const int> data) // since C++20
    {
        cout << "data = ";
        for (const int e : data)
            cout << e << ' ';
        cout << '\n';
    }
    void Data()
    {
        array<int, 4> container{1, 2, 3, 4};
        // Prefer container.data() over &container[0]
        pointer_func(container.data(), container.size());
        // span (C++20) is a safer alternative to separated pointer/size.
        span_func({container.data(), container.size()});
    }
    // Output:
    // data = 1 2 3 4 
    // data = 1 2 3 4

};

int main()
{
    MyElementAccess myarray;
    myarray.At();

    return 0;
}
