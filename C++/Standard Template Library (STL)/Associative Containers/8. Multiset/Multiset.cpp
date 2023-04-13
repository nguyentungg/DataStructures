//---------------------------------
// General Informations
//---------------------------------
// - The value is itself the key, can have same value (not need to unique value).
// - The value of the elements in a set cannot be modified once in the container (the elements are always const).
// - The elements in a set are always sorted.
// - `set` containers are slower than unordered_set to access individual elements by their key, 
//   but they allow the direct iteration on subsets based on their order.
// - Implemented as binary search trees.

#include <set>

std::multiset<int> s, so;
std::multiset<int>::iterator it;
std::pair<std::multiset<int>::iterator,bool> ret; // Pair of values. Values can be accessed through its public members `first` and `second`.
//---------------------------------
// General Operations
//---------------------------------

// Insert
s.insert (it,value);                                // index
int myints[]= {5,10,15}; 
s.insert (myints,myints+3);                           // insert an array
s.insert(value);                                    // tail.

s.emplace(value);                                   // The element position is always following this ordering.
auto ret = s.emplace(value);                        // Check insert result
if (!ret.second) 
    std::cout << "foo already exists in myset\n";
it = s.emplace_hint (s.cend()/it,value);            // index

// Access
it = s.begin();
it = s.find(value);
++it;

// Size
unsigned int size = s.size();

// Iterate
for(std::multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
}
for (const std::string& x: s)
  std::cout << ' ' << x;
std::cout << '\n';

// Remove
s.erase(value);
s.erase (it);
s.erase (s.begin()/it, s.end());

//Exchanges the content of 2 containers
s.swap(so);

// Clear
s.clear();


//---------------------------------
// Container Observers
//---------------------------------

// key_comp
std::multiset<int>::key_compare mycomp = s.key_comp();
int highest;

highest=*s.rbegin();
std::multiset<int>::iterator it=s.begin();
do {
  std::cout << ' ' << *it;
} while ( mycomp(*(++it),highest) );

// value_comp
std::multiset<int>::value_compare mycomp = s.value_comp();
int highest=*s.rbegin();
std::multiset<int>::iterator it=s.begin();
do {
  std::cout << ' ' << *it;
} while ( mycomp(*(++it),highest) );


//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists
bool exists = (s.find(value) != s.end());
it = s.find(value);

// Count the number of elements with a certain value
unsigned int count = s.count(value);

// lower_bound & upper_bound
std::multiset<int>::iterator itlow,itup;
                                             // 10 20 30 40 50 60 70 80 90
itlow=myset.lower_bound (30);                //        ^
itup=myset.upper_bound (60);                 //                    ^

s.erase(itlow,itup);                         // 10 20             70 80 90

// Get range of equal elements
// *Note: Because all elements in a set container are unique, the range returned will contain a single element at most.
std::pair<std::multiset<int>::const_iterator std::multiset<int>::const_iterator> ret;
ret = myset.equal_range(30);
//Get
std::cout << "the lower bound points to: " << *ret.first << '\n';   //the lower bound points to: 30
std::cout << "the upper bound points to: " << *ret.second << '\n';  //the upper bound points to: 40
// Returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound),
// and pair::second is the upper bound (the same as upper_bound).