//---------------------------------------------------------
// Forward lists are implemented as Singly-Linked Lists
//--------------------------------------------------------
std::forward_list<int> fl, fl1 , fl2;
std::forward_list<int>::iterator it;
//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
fl.push_front(value);                                       // head
fl.emplace_front(value);                                    // head
fl.insert_after(fl.before_begin(), value);                  // head
fl.insert_after(fl.begin(), value);                         // index
fl.insert_after(fl.begin()/it, NumberOfTimes, value);       // index
fl.emplace_after(fl.begin(), value);                        // index
fl.insert_after(fl.begin()/it, array.begin(), array.end()); // merge with other array at tail
fl.insert_after(fl.begin()/it,{1,2,3});                     // merge with other array after begin. Ex: 10 [1 2 3] 20 20 11 22 33
                                                            //                          (Begin(index 0) ^)(^ ^ ^ New Input)
fl.push_back(value);                                        // tail

// Access head, index, tail
int head = fl.front();                          // head
it = fl.before_begin();                         // before head
it = std::next(fl.begin(), index);		        // index
int tail = fl.back();                           // tail

// Iterate
for(std::forward_list<int>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
fl.pop_front();                               // head
fl.erase_after(fl.begin()/it);                // index
fl.erase_after(fl.begin()/it, fl.end()/it);   // after index
fl.pop_back();                                // tail

// Clear
fl.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// splice_after: Transfer elements from forward_list to forward_list
//	    splice_after(iterator pos, forward_list &x)
//  	splice_after(iterator pos, forward_list &x, iterator i)
//  	splice_after(iterator pos, forward_list &x, iterator first, iterator last)
// Ex:  fl1: 1 2 3 4 
//      fl2: 10 20 30
it = fl1.begin();       // it = 1
fl1.splice_after(fl1.before_begin(), fl2); // Remove elements from fl2 and add to fl1
// fl1: 10 20 30 1 2 3 4
// fl2 (empty)               => 'it' still point to 1
fl2.splice_after(fl2.before_begin(), fl1, fl1.begin(), it);
// fl1: 10 1 2 3 4
// fl2: 20 30
fl1.splice_after( fl1.before_begin(), fl2, fl2.begin()); // fl1: 1 10 20 | 30 3 4
// fl1: 30 10 1 2 3
// fl2: 20
// *Notice that what is moved is AFTER the iterator

// Remove: Remove an element by value ( erase remove elements by their position (using an iterator))
l.remove(value);
l.remove_if (single_digit); //EX: bool single_digit (const int& value) { return (value<10); }

// Unique: Remove duplicates
l.unique();

// Merge: Merge two sorted lists and inserts them into their ordered position (Both containers shall already be ordered by l.sort().)
l.merge(list2);
l1.merge(l2,mycomparison); // bool mycomparison (double first, double second){ return ( int(first)<int(second) ); }

// Sort: Sort the list
l.sort();

// Reverse: Reverse the list order (still ok with not ordered list)
l.reverse();