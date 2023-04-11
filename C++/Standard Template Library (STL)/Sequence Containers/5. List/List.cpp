std::list<int> l, l1 , l2;
std::list<int>::iterator it;
//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
l.push_front(value);                    // head
l.insert(l.begin() + index, value);     // index
l.push_back(value);                     // tail

// Access head, index, tail
int head = l.front();                                           // head
int value = std::next(l.begin(), index);		        // index
int tail = l.back();                                            // tail

// Size
unsigned int size = l.size();

// Iterate
for(std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
l.pop_front();                  // head
l.erase(l.begin() + index);     // index
l.pop_back();                   // tail

// Clear
l.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Splice: Transfer elements from list to list
//	    splice(iterator pos, list &x)
//  	splice(iterator pos, list &x, iterator i)
//  	splice(iterator pos, list &x, iterator first, iterator last)
// l.splice(l.begin() + index, list2); ?? Can Xac Nhan
// Ex:  l1: 1 2 3 4 
//      l2: 10 20 30
it = l1.begin();        // it = 1
it++;                   // it points to 2 (=2)
l1.splice (l1.begin(), l2);
// l1: 1 10 20 30 2 3 4
// l2 (empty)
l2.splice (l2.begin(), l1, it);
// l1: 1 10 20 30 3 4
// l2: 2                => "it" is now invalid.
it = mylist1.begin();
std::advance(it,3);     // "it" points now to 30
l1.splice ( l1.begin(), l1, it, l1.end()); // l1: 1 10 20 | 30 3 4
// l1: 30 3 4 1 10 20
// l2: 2 

// Remove: Remove an element by value ( erase remove elements by their position (using an iterator))
l.remove(value);
l.remove_if (single_digit); //EX: bool single_digit (const int& value) { return (value<10); }

// Unique: Remove duplicates
l.unique();

// Merge: Merge two sorted lists
l.merge(list2);
l1.merge(l2,mycomparison); // bool mycomparison (double first, double second){ return ( int(first)<int(second) ); }

// Sort: Sort the list
l.sort();

// Reverse: Reverse the list order
l.reverse();