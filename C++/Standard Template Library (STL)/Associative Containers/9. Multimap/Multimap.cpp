//---------------------------------
// General Informations
//---------------------------------
// - Allow Duplicate

// -`Multimap` keep all their elements sorted. The elements in a `multimap` are always sorted by its key.

// - In a 'multimap', the key values are generally used to sort and uniquely identify the elements, 
//   while the 'mapped' values store the content associated to this key. 

// -`Multimap` are generally slower than `unordered_multimap` to access individual elements by their key, 
//   but they allow the direct iteration on subsets based on their order.

// - Implemented as 'binary search trees'.
#include <map>

std::multimap<std::string, std::string> mul, mtmo;
std::multimap<char,int>::iterator it;

//---------------------------------
// General Operations
//---------------------------------

// Insert
mtm.insert (mtm.begin()/it, std::pair<char,int>("key","value"));        // index (insert after index)
mtmo.insert(m1.begin(),m1.find("key"));                             // index (move a range of mtm1 to mtmo)
mtm.insert(std::pair<std::string, std::string>("key","value"));  // tail
mtm.emplace("key", "value");                                          // tail (allow duplicate key) (auto sort)
mtm.emplace_hint(mtm.begin()/it, "key", "value");                       // tail (allow duplicate key) with a a hint on the insertion position (auto sort)


// Checking
it = mtm.insert ( std::pair<char,int>("key", "value") );
if (it.second == false) {
  std::cout << "element 'z' already existed";
  std::cout << " with a value of " << it.first->second << '\n';
  //                           display exited value ^
}

// Access
it=mtm.lower_bound ('key');   // Returns an iterator pointing to the first element whose key is not considered to go BEFORE key.
it=mtm.upper_bound ('key');     // Returns an iterator pointing to the first element whose key is considered to go AFTER key.
// optional:  it->first as key ; it->second as value
mtm.equal_range('key');       // Returns the bounds of a range that includes all the elements which have a key equivalent to key.
                            // Because the elements in a map container have unique keys, the range returned will contain a single element at most.
// Size
unsigned int size = mtm.size();

// Iterate
for(std::multimap<std::string, std::string>::iterator it = mtm.begin(); it != mtm.end(); it++) {
    std::cout << (*it).first << " " << (*it).second << std::endl;
}
for (char ch='a'; ch<='d'; ch++)
{
    pair <multimap<char,int>::iterator, multimap<char,int>::iterator> ret;
    ret = mymm.equal_range(ch);
    cout << ch << " =>";
    for (multimap<char,int>::iterator it=ret.first; it!=ret.second; ++it)
      cout << ' ' << it->second;
    cout << '\n';
}
// mymm contains:
// a => 10
// b => 20 30 40
// c => 50 60
// d => 60

// Remove by key
it=mtm.find("key");
mtm.erase(mtm.begin()/it);                   // erasing by iterator (position)
mtm.erase("key");                          // erasing by key
mtm.erase (mtm.begin()/it, mtm.end() );        // erasing by range


// Clear
mtm.clear();

// Exchanges
mtm.swap(mtmo);                     //Exchanges the content between two map


//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool/it exists = (mtm.find("key") != mtm.end());

// Count the number of elements with a certain key
unsigned int count = mtm.count("key");


//---------------------------------
// Container-Specific Observers
//---------------------------------

// Return key comparison object
std::map<char,int>::key_compare keycomp = mtm.key_comp();
char highest = mtm.rbegin()->first;     // key value of last element
std::map<char,int>::iterator it = mtm.begin();
do {
  std::cout << it->first << " => " << it->second << '\n';
} while ( keycomp((*it++).first, highest) );

// Return value comparison object
std::pair<char,int> highest = *mtm.rbegin();          // last element
std::map<char,int>::iterator it = mtm.begin();
do {
  std::cout << it->first << " => " << it->second << '\n';
} while ( mtm.value_comp()(*it++, highest) );