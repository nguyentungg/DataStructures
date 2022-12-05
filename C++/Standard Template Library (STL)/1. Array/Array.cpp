#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array> // for array, at()
#include <tuple> // for get()
using namespace std;
int main()
{
    // construction uses aggregate initialization
    array<int, 3> a1{{1, 2, 3}};  // double-braces required in C++11 prior to
                                       // the CWG 1270 revision (not needed in C++11
                                       // after the revision and in C++14 and beyond)
    array<int, 3> a2 = {1, 2, 3}; // double braces never required after =
    array<string, 2> a3 = {string("a"), "b"};

    // container operations are supported
    sort(a1.begin(), a1.end());
    reverse_copy(a2.begin(), a2.end(),
                      ostream_iterator<int>(cout, " "));
    cout << '\n';
    // Printing array elements using at()
    cout << "The array elements are (using at()) : ";
    cout << a1.at(0) << " ";
    // Printing array elements using get()
    cout << "The array elements are (using get()) : ";
    cout << get<0>(a1) << " " << get<1>(a1) << " ";
    cout << get<0>(a1) << " " << get<1>(a1) << " ";
    cout << get<2>(a1) << " " << get<3>(a1) << " ";
    cout << get<4>(a1) << " " << get<5>(a1) << " ";
    
    // Printing array elements using operator[]
    cout << "The array elements are (using operator[]) : ";
    for (int i = 0; i < 6; i++){
        cout << a1[i] << " ";
        
    }
    // ranged for loop is supported
    for (const auto &s : a3)
        cout << s << ' ';
    // deduction guide for array creation (since C++17)
    [[maybe_unused]] array a4{3.0, 1.0, 4.0}; // -> array<double, 3>
}
// Output:
// 3 2 1
// a b




// The array elements are (using at()) : 1 2 3 4 5 6 
// The array elements are (using get()) : 1 2 3 4 5 6 
// The array elements are (using operator[]) : 1 2 3 4 5 6 
