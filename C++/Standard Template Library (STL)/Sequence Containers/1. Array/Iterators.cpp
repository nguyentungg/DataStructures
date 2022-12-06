#include <array>
#include <iostream>
#include <algorithm> //for_each
#include <iomanip>
#include <string>
#include <string_view>
#include <vector>
#include <iterator>

using namespace std;
class MyIterators
{
public:
    array<int, 0> empty;

    // begin & cbegin
    // Returns an iterator to the first element of the array.
    // If the array is empty, the returned iterator will be equal to end().

    // end & cend
    // Returns an iterator to the element following the last element of the array.
    // This element acts as a placeholder; attempting to access it results in undefined behavior.
    void BeginCbeginEndAndCend()
    {
        cout << boolalpha;
        array<int, 0> empty;
        cout << "1) "
             << (empty.begin() == empty.end()) << ' '     // true
             << (empty.cbegin() == empty.cend()) << '\n'; // true
                                                          // *(empty.begin()) = 42; // => undefined behaviour at run-time

        array<int, 4> numbers{5, 2, 3, 4};
        cout << "2) "
             << (numbers.begin() == numbers.end()) << ' '    // false
             << (numbers.cbegin() == numbers.cend()) << '\n' // false
             << "3) "
             << *(numbers.begin()) << ' '    // 5
             << *(numbers.cbegin()) << '\n'; // 5

        *numbers.begin() = 1;
        cout << "4) " << *(numbers.begin()) << '\n'; // 1
        // *(numbers.cbegin()) = 42; // compile-time error:
        // read-only variable is not assignable

        // print out all elements
        cout << "5) ";
        for_each(numbers.cbegin(), numbers.cend(), [](int x)
                 { cout << x << ' '; });
        cout << '\n';

        constexpr array constants{'A', 'B', 'C'};
        static_assert(constants.begin() != constants.end());   // OK
        static_assert(constants.cbegin() != constants.cend()); // OK

        static_assert(*constants.begin() == 'A');  // OK
        static_assert(*constants.cbegin() == 'A'); // OK
        // *constants.begin() = 'Z'; // compile-time error:
        // read-only variable is not assignable

        // Output:
        // 1) true true
        // 2) false false
        // 3) 5 5
        // 4) 1
        // 5) 1 2 3 4
    }

    // Returns a reverse iterator to the first element of the reversed array.
    // It corresponds to the last element of the non-reversed array. If the array is empty, the returned iterator is equal to rend().
    void Crbegin()
    {
        constexpr array<string_view, 8> data = {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};

        array<string, size(data)> arr;

        copy(data.cbegin(), data.cend(), arr.begin());
        //            ^            ^           ^

        auto print = [](const string_view s)
        { cout << s << ' '; };

        print("Print 'arr' in direct order using [cbegin, cend):\t");
        for_each(arr.cbegin(), arr.cend(), print);
        //                ^             ^
        print("\n\nPrint 'arr' in reverse order using [crbegin, crend):\t");
        for_each(arr.crbegin(), arr.crend(), print);
        //               ^^            ^^
        print("\n");

        // Output:
        // Print 'arr' in direct order using [cbegin, cend):        ▁ ▂ ▃ ▄ ▅ ▆ ▇ █
        // Print 'arr' in reverse order using [crbegin, crend):     █ ▇ ▆ ▅ ▄ ▃ ▂ ▁
    }

    // Returns an iterator to the reverse-beginning of the given range.
    void Rbegin()
    {
        vector<int> v = {3, 1, 4};
        auto vi = rbegin(v); // the type of `vi` is vector<int>::reverse_iterator
        cout << "*vi = " << *vi << '\n';

        *rbegin(v) = 42; // OK: after assignment v[2] == 42
                         //  *crbegin(v) = 13; // error: the location is read-only

        int a[] = {-5, 10, 15};
        auto ai = rbegin(a); // the type of `ai` is reverse_iterator<int*>
        cout << "*ai = " << *ai << '\n';

        auto il = {3, 1, 4};
        // the type of `it` below is reverse_iterator<int const*>:
        for (auto it = rbegin(il); it != rend(il); ++it)
            cout << *it << ' ';

        // Output:
        // *vi = 4
        // *ai = 15
        // 4 1 3
    }

    // Returns a reverse iterator to the element following the last element of the reversed array. 
    // It corresponds to the element preceding the first element of the non-reversed array. 
    // This element acts as a placeholder, attempting to access it results in undefined behavior. 
    void RendAndCrend()
    {
        array<int, 11> a{1, 11, 11, 35, 0, 12, 79, 76, 76, 69, 40};

        // print elements of array in reverse order using const_reverse_iterator`s
        for_each(a.crbegin(), a.crend(), [](int e){ cout << e << ' '; });
        //           ^^           ^^
        cout << '\n';

        // modify each element of array using non-const reverse_iterator`s
        for_each(a.rbegin(), a.rend(), [](int &e){ e += 32; });
        //         ^           ^              ^

        // print elements as chars in reverse order using const_reverse_iterator`s
        for_each(a.crbegin(), a.crend(), [](char e){ cout << e; });
        //         ^^           ^^          ^^^^
        cout << '\n';

        // Output:
        // 40 69 76 76 79 12 0 35 11 11 1 
        // Hello, C++!
    }
};

int main()
{
    MyIterators myarray;

    return 0;
}
