# C++ Member functions
### **Implicitly-defined member functions**
- **(constructor)(implicitly declared):**
	initializes the array following the rules of aggregate initialization (note that default initialization may result in indeterminate values for non-class T)(public member function)
- **(destructor)(implicitly declared):**
	destroys every element of the array(public member function)
- **operator=(implicitly declared):**
	overwrites every element of the array with the corresponding element of another array(public member function)

### **Element access**
    - at(C++11)	        => access specified element with bounds checking (public member function)
    - operator[](C++11) =>	access specified element(public member function)
    - front(C++11)	    => access the first element(public member function)
    - back(C++11)	    => access the last element(public member function)
    - data(C++11)	    => direct access to the underlying array(public member function)
### **Iterators**

    - begin (C++11)
    - cbegin (C++11)	
    returns an iterator to the beginning(public member function)

    - end (C++11)
    - cend(C++11)	
    returns an iterator to the end(public member function)
    
    - rbegin(C++11)
    - crbegin(C++11)
    returns a reverse iterator to the beginning (public member function)
    
    - rend(C++11)
    - crend(C++11)
    returns a reverse iterator to the end(public member function)

### **Capacity**
    - empty(C++11)	    => checks whether the container is empty(public member function)
    - size(C++11)	    => returns the number of elements(public member function)
    - max_size(C++11)	=> returns the maximum possible number of elements(public member function)

### **Operations**
    - fill(C++11)	=> fill the container with specified value(public member function)
    - swap(C++11)	=> swaps the contents(public member function)

### **Non-member functions**

    - operator==  (removed in C++20)
    - operator!=  (removed in C++20)
    - operator<   (removed in C++20)
    - operator<=  (removed in C++20)
    - operator>   (removed in C++20)
    - operator>=  (removed in C++20)
    - operator<=> (C++20)
    lexicographically compares the values in the array(function template)
```
- std::get(std::array)(C++11)	 => accesses an element of an array(function   template)

- std::swap(std::array)(C++11)   => specializes the std::swap algorithm(function template)

- to_array(C++20)	             => creates a std::array object from a built-in arra(function template)
```

### **Helper classes**
```
- std::tuple_size<std::array>(C++11)	obtains the size of an array(class template specialization)

- std::tuple_element<std::array>(C++11)	obtains the type of the elements of array(class template specialization)
```

# Data Structure and Algorithm Lab
If you love this repository you can join with me on Data Structure and Algorithm Lab.

Together we will research and create useful things for the community.

[Discord](https://discord.gg/N8CrS3Ccsp)