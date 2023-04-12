//---------------------------------
// General Informations
//---------------------------------
// - Not allow duplicate, Key must be unique
#include <map>

std::map<std::string, std::string> m, mo;
std::pair<std::map<char,int>::iterator,bool> it;
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
std::string value = m.at('key');
it=m.lower_bound ('key');   // Returns an iterator pointing to the first element whose key is not considered to go BEFORE key.
it=m.upper_bound ('key');     // Returns an iterator pointing to the first element whose key is considered to go AFTER key.
// optional:  it->first as key ; it->second as value
m.equal_range('key');       // Returns the bounds of a range that includes all the elements which have a key equivalent to key.
                            // Because the elements in a map container have unique keys, the range returned will contain a single element at most.


//Update
m['key'] = value;

// Size
unsigned int size = m.size();

// Iterate
for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << (*it).first << " " << (*it).second << std::endl;
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
// Container-Specific Observers
//---------------------------------

// Return key comparison object
std::map<char,int>::key_compare keycomp = m.key_comp();
char highest = m.rbegin()->first;     // key value of last element
std::map<char,int>::iterator it = m.begin();
do {
  std::cout << it->first << " => " << it->second << '\n';
} while ( keycomp((*it++).first, highest) );

// Return value comparison object
std::pair<char,int> highest = *m.rbegin();          // last element
std::map<char,int>::iterator it = m.begin();
do {
  std::cout << it->first << " => " << it->second << '\n';
} while ( m.value_comp()(*it++, highest) );