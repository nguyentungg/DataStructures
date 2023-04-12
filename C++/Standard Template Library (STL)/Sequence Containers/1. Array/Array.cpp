std::array<int,Size> a;
//---------------------------------
// General Operations
//---------------------------------

// Access head, index, tail
int head = a.front();       // head, returns a reference to the first element 
head = a[0];                // or using array style indexing

int value = a.at(index);    // index
value = a[index];           // or using array style indexing

a.data()                    // returns a pointer to the first element in the array.
a.back();                   // tail

// Insert head, index, tail
a[index]= value;
a.at(index) = value;
a.back() = value;           // replace tail with a value
a.fill(value);              // set val as the value for all the elements in the array.


// Size
a.size()                    // The number of elements contained in the array include (initialize).
sizeof(a)                   // returns the size in bytes

// Iterate
for (int& i : a) std::cout << ' ' << i;
for (int i=0; i<10; i++) myarray.at(i) = i+1;

// Exchanges 
a.swap (a2); //exchange data between two arrays.

// Is Empty ?
a.empty()