#include <iostream>
#include <array>

using namespace std;
class MyHelperClasses
{
public:
    template <class T>
    void TupleSize(T)
    {
        int a[tuple_size<T>::value]; // can be used at compile time
        cout << size(a) << '\n';
        // Output:
        // 3
    }

    void TupleElement()
    {
        // define array and get the type of the element at position 0
        array<int, 10> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        using T = tuple_element<0, decltype(data)>::type; // int

        cout << boolalpha;
        cout << is_same<T, int>::value << '\n';

        const auto const_data = data;
        using CT = tuple_element<0, decltype(const_data)>::type; // const int

        // the result of tuple_element depends on the cv-qualification of the tuple-like type
        cout << is_same<T, CT>::value << '\n';
        cout << is_same<CT, const int>::value << '\n';

        // Output:
        // true
        // false
        // true
    }
};

int main()
{
    MyHelperClasses myarray;
    array<float, 3> arr;
    myarray.TupleSize(arr);
    myarray.TupleElement();
    return 0;
}
