//---------------------------------
// General Informations
//---------------------------------
// - The value is itself the key, each value must be unique, it identifies it uniquely.
// - Keys are immutable.
// - The value of the elements in a set cannot be modified once in the container (the elements are always const).
// - The elements in the `unordered_set` are not sorted in any particular order.
// - `unordered_set` are faster than `set` to access individual elements by their key, 
//   although they are generally less efficient for range iteration through a subset of their elements.

#include <unordered_set>

std::unordered_set<std::string> us;
std::unordered_set<std::string>::const_iterator it
//---------------------------------
// General Operations
//---------------------------------

//Initialize
std::unordered_set<std::string> s = {"Mercury","Venus"};

// Insert
s.insert (it,value);                                // index
s.insert ("value");                                 // copy insertion
s.insert (value+"addon");                           // move insertion
s.insert (myarray.begin(), myarray.end());          // range insertion
s.insert ( {"purple","orange"} );                   // initializer list insertion

s.emplace(value);                                   // Inserts a new element in the set, if unique.
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
for (const std::string& x: s) std::cout << ' ' << x;
for (auto& x: s) std::cout << x << std::endl;


// Remove
s.erase(value);                         // erasing by key
s.erase (s.begin()/it);                 // erasing by iterator
s.erase (s.begin()/it, s.end());        // erasing by range



//Exchanges the content of 2 containers
s.swap(so); //Note that it will revert the elements to the opposite after being swapped.

// Clear
s.clear();


//---------------------------------
// Container Observers
//---------------------------------

// key_comp
std::unordered_set<int>::key_compare mycomp = s.key_comp();
int highest;

highest=*s.rbegin();
std::unordered_set<int>::iterator it=s.begin();
do {
  std::cout << ' ' << *it;
} while ( mycomp(*(++it),highest) );

// value_comp
std::unordered_set<int>::value_compare mycomp = s.value_comp();
int highest=*s.rbegin();
std::unordered_set<int>::iterator it=s.begin();
do {
  std::cout << ' ' << *it;
} while ( mycomp(*(++it),highest) );


//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists
bool exists = (s.find(value) != s.end());
it = s.find(value);
if ( it == s.end() )
    std::cout << "not found in myset";
else
    std::cout << *got << " is in myset";

// Count the number of elements with a certain value
unsigned int count = s.count(value);
for (auto& x: {"hat","sunglasses","suit","t-shirt"}) {
   if (s.count(x)>0)
     std::cout << "myset has " << x << std::endl;
   else
     std::cout << "myset has no " << x << std::endl;
}

// lower_bound & upper_bound
std::unordered_set<int>::iterator itlow,itup;
                                             // 10 20 30 40 50 60 70 80 90
itlow=s.lower_bound (30);                //        ^
itup=s.upper_bound (60);                 //                    ^
s.erase(itlow,itup);                         // 10 20             70 80 90

// equal_range
// *Note: Because all elements in a set container are unique, the range returned will contain a single element at most.
std::pair<std::unordered_set<int>::const_iterator std::unordered_set<int>::const_iterator> ret;
ret = s.equal_range(30);
//Get
std::cout << "the lower bound points to: " << *ret.first << '\n';   //the lower bound points to: 30
std::cout << "the upper bound points to: " << *ret.second << '\n';  //the upper bound points to: 40
// Returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound),
// and pair::second is the upper bound (the same as upper_bound).

//---------------------------------
// Buckets
//---------------------------------
// bucket_count
unsigned n = s.bucket_count();
for (unsigned i=0; i<n; ++i) {
  std::cout << "bucket #" << i << " contains:";
  for (auto it = s.begin(i); it!=s.end(i); ++it)
    std::cout << " " << *it;
}

//max_size, max_bucket_count and max_load_factor
std::cout << "max_size = " << s.max_size() << std::endl;
std::cout << "max_bucket_count = " << s.max_bucket_count() << std::endl;
std::cout << "max_load_factor = " << s.max_load_factor() << std::endl;

//bucket_size
s.bucket_size(index)

//Return bucket number
s.bucket("value");

//load_factor and max_load_factor
std::cout << "load_factor = " << s.load_factor() << std::endl;
std::cout << "max_load_factor = " << s.max_load_factor() << std::endl;

//rehash
s.rehash(number);   //Sets the number of buckets in the container to n or more.

//reserve
s.reserve(number); //Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements.

//hash_function
typedef std::unordered_set<std::string> stringset;
stringset::hasher hf = s.hash_function(); // Returns the hash function object used by the unordered_set container.

//key_eq
bool case_insensitive = s.key_eq()("checking","CHECKING"); //Returns the key equivalence comparison predicate used by the unordered_set.
std::cout << ( case_insensitive ? "case insensitive" : "case sensitive" );