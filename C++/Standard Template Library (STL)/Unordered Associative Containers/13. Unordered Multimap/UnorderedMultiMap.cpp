//---------------------------------
// General Informations
//---------------------------------
// - Allow duplicate, Key can be same
// - The elements in the unordered_map are not sorted
// - Allow for fast access to individual elements directly by their key values.
// - Same header <unordered_map> with unordered_map.
#include <unordered_map>

std::unordered_multimap<std::string,int> m, mo;
std::pair<std::unordered_multimap<string,int>::iterator,bool> it;
//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert (m.begin()/it, std::pair<char,int>("key","value"));        // index (insert after index)
mo.insert(m1.begin(),m1.find("key"));                             // index (move a range of m1 to mo)
m.insert(std::pair<std::string, std::string>("key","value"));  // tail
m.emplace("key", "value");                                          // tail (key must unique) (auto sort)
m.emplace_hint(m.begin()/it, "key", "value");                       // tail (key must unique) with a a hint on the insertion position (auto sort)


// Checking
it = m.insert ( std::pair<char,int>("key", "value") );
if (it.second == false) {
  std::cout << "element 'z' already existed";
  std::cout << " with a value of " << it.first->second << '\n';
  //                           display exited value ^
}

// Access
m.equal_range('key');       // Returns the bounds of a range that includes all the elements which have a key equivalent to key.
                            // Because the elements in a map container have unique keys, the range returned will contain a single element at most.
// Size
unsigned int size = m.size();

// Iterate
for(auto it = m.begin(i); it!=m.end(i); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
}
for (auto& x: m) {
  std::cout << x.first << ": " << x.second << std::endl;
}

// Remove by key
it=m.find("key");
m.erase(m.begin()/it);                   // erasing by iterator (position)
m.erase("key");                          // erasing by key
m.erase (m.begin()/it, m.end() );        // erasing by range


// Clear
m.clear();

// Exchanges
m.swap(mo);                     //Exchanges the content between two map


//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool/it exists = (m.find("key") != m.end());

// Count the number of elements with a certain key
unsigned int count = m.count("key");


//---------------------------------
// Buckets
//---------------------------------
// A bucket is a slot in the container's internal hash table to which elements are assigned based on the hash value of their key.

// Bucket Count
unsigned n = m.bucket_count();    //The current amount of buckets(elements).

// The maximum number of buckets, max size and max load factor.
m.max_size()
m.max_bucket_count()
m.max_load_factor()

// Bucker Size
m.bucket_size(index);

// Bucket number 
m.bucket ('key'); //where the element with key k is located.


//---------------------------------
// Hash policy
//---------------------------------
// The load factor is the ratio between the number of elements in the container (its size) and the number of buckets (bucket_count):
// load_factor = size / bucket_count
m.load_factor(); //The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket)

// Max load factor
float z = m.max_load_factor();
m.max_load_factor ( z / 2.0 );

// Rehash
m.rehash(number); // A rehash is the reconstruction of the hash table

m.reserve(number); //Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements.
// Avoided the multiple rehashes that the increases in container size could have produced and optimized the size of the hash table.


//---------------------------------
// Container-Specific Observers
//---------------------------------

// Hash function
typedef std::unordered_multimap<std::string,std::string> stringmap;

void MyFunction(){
  stringmap mymap;
  stringmap::hasher fn = mymap.hash_function();

  std::cout << "this: " << fn ("this") << std::endl;
  std::cout << "thin: " << fn ("thin") << std::endl;
}

// Get key equality comparison object(same as ==)
bool case_insensitive = m.key_eq()("key","KEY");
