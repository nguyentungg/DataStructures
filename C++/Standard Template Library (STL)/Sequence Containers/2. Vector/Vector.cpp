std::vector<int> v;
std::vector<int> other;
int * pointer;

//---------------------------------
// General Operations
//---------------------------------

// Initialize
vector<int> v (3,100); // => 100 100 100

// Size
unsigned int size = v.size();
v.resize(5); // resize vector to 5 element
v.resize(8,100); // resize vector to 8 and fill 100 until it reach 8 elements. Ex: 1 2 3 4 5 100 100 100
v.resize(12); // resize vector to 12 and no fill. Ex: 1 2 3 4 5 100 100 100 0 0 0 0

// Insert head, index, tail
v.insert(v.begin(), value);                 // head
v.insert(v.begin() + index, value);         // index
v.insert (v.end(), numberOfTimes, value);   // Add a number of times value
v.push_back(value);                         // tail

// Access head, index, tail
int head = v.front();       // head, returns a reference to the first element 
head = v[0];                // or using array style indexing

int value = v.at(index);    // index
value = v[index];           // or using array style indexing

int tail = v.back();        // tail
tail = v[v.size() - 1];     // or using array style indexing

// Iterate
for(int i : myvector) cout << i << endl;
for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
v.erase(v.begin());             // head
v.erase(v.begin() + index);     // index
v.pop_back();                   // tail

// Exchanges the content from a vector to vector (must have same type)
v.swap(other);

// Clear
v.clear();


// allocate an array with space for 5 elements using vector's allocator:
p = v.get_allocator().allocate(5);
// construct values in-place on the array:
for (i=0; i<5; i++) v.get_allocator().construct(&p[i],i);
// destroy and deallocate:
for (i=0; i<5; i++) v.get_allocator().destroy(&p[i]);
v.get_allocator().deallocate(p,5);

v.shrink_to_fit(); // Requests the container to reduce its capacity to fit its size. 
v.reserve(100);   // make vector capacity be at least enough to contain n elements.