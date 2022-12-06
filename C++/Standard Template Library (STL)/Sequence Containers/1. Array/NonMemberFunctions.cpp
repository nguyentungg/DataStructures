#include <array>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <utility>
#include <memory>

using namespace std;
class MyNonMemberFunctions
{
public:
    // Extracts the Ith element element from the array.
    // I must be an integer value in range [0, N). This is enforced at compile time as opposed to at() or operator[].
    void Get()
    {
        array<int, 3> arr;

        // set values:
        get<0>(arr) = 1;
        get<1>(arr) = 2;
        get<2>(arr) = 3;

        // get values:
        cout << "(" << get<0>(arr) << ", " << get<1>(arr)
             << ", " << get<2>(arr) << ")\n";

        // Output:
        // (1, 2, 3)
    }

    void Swap()
    {
        array<int, 3> alice{1, 2, 3};
        array<int, 3> bob{7, 8, 9};

        auto print = [](const int &n)
        { cout << ' ' << n; };

        // Print state before swap
        cout << "alice:";
        for_each(alice.begin(), alice.end(), print);
        cout << "\n""bob  :";
        for_each(bob.begin(), bob.end(), print);
        cout << '\n';

        cout << "-- SWAP\n";
        swap(alice, bob);

        // Print state after swap
        cout << "alice:";
        for_each(alice.begin(), alice.end(), print);
        cout << "\n""bob  :";
        for_each(bob.begin(), bob.end(), print);
        cout << '\n';

        // Output:
        // alice: 1 2 3
        // bob  : 7 8 9
        // -- SWAP
        // alice: 7 8 9
        // bob  : 1 2 3
    }

    void ToArray()
    {
        // copies a string literal
        auto a1 = to_array("foo");
        static_assert(a1.size() == 4);

        // deduces both element type and length
        auto a2 = to_array({0, 2, 1, 3});
        static_assert(is_same_v<decltype(a2), array<int, 4>>);

        // deduces length with element type specified
        // implicit conversion happens
        auto a3 = to_array<long>({0, 1, 3});
        static_assert(is_same_v<decltype(a3), array<long, 3>>);

        auto a4 = to_array<pair<int, float>>({{3, .0f}, {4, .1f}, {4, .1e23f}});
        static_assert(a4.size() == 3);

        // creates a non-copyable array
        auto a5 = to_array({make_unique<int>(3)});
        static_assert(a5.size() == 1);

        // error: copying multidimensional arrays is not supported
        // char s[2][6] = { "nice", "thing" };
        // auto a6 = to_array(s);
    }
};

int main()
{
    MyNonMemberFunctions myarray;

    array<int, 3> alice{1, 2, 3};
    array<int, 3> bob{7, 8, 9};
    array<int, 3> eve{1, 2, 3};

    cout << boolalpha;

    // Compare non equal containers
    cout << "alice == bob returns " << (alice == bob) << '\n';
    cout << "alice != bob returns " << (alice != bob) << '\n';
    cout << "alice <  bob returns " << (alice < bob) << '\n';
    cout << "alice <= bob returns " << (alice <= bob) << '\n';
    cout << "alice >  bob returns " << (alice > bob) << '\n';
    cout << "alice >= bob returns " << (alice >= bob) << '\n';

    cout << '\n';

    // Compare equal containers
    cout << "alice == eve returns " << (alice == eve) << '\n';
    cout << "alice != eve returns " << (alice != eve) << '\n';
    cout << "alice <  eve returns " << (alice < eve) << '\n';
    cout << "alice <= eve returns " << (alice <= eve) << '\n';
    cout << "alice >  eve returns " << (alice > eve) << '\n';
    cout << "alice >= eve returns " << (alice >= eve) << '\n';

    // Output:
    // alice == bob returns false
    // alice != bob returns true
    // alice <  bob returns true
    // alice <= bob returns true
    // alice >  bob returns false
    // alice >= bob returns false
    //  
    // alice == eve returns true
    // alice != eve returns false
    // alice <  eve returns false
    // alice <= eve returns true
    // alice >  eve returns false
    // alice >= eve returns true
    return 0;
}
