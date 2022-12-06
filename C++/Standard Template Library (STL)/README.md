# C++ Containers library
The Containers library is a generic collection of class templates and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks. There are two (until C++11)three (since C++11) classes of containers:
- sequence containers
- associative containers
- unordered associative containers (since C++11)

each of which is designed to support a different set of operations. 


### **Sequence containers**

Sequence containers implement data structures which can be accessed sequentially.

    - array(C++11)        => static contiguous array(class template)
    - vector              => dynamic contiguous array(class template)
    - deque               => double-ended queue(class template)
    - forward_list(C++11) => singly-linked list(class template)
    - list                => doubly-linked list(class template)

### **Associative containers**
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

    - set	   =>  collection of unique keys, sorted by keys(class template)
    - map	   =>  collection of key-value pairs, sorted by keys, keys are unique(class template)
    - multiset =>  collection of keys, sorted by keys(class template)
    - multimap =>  collection of key-value pairs, sorted by keys(class   template)

### **Unordered associative containers (since C++11)**
Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity).

    - unordered_set(C++11)        =>   collection of unique keys, hashed by keys(class template)
    - unordered_map(C++11)        =>   collection of key-value pairs, hashed by keys,  keys are unique(class template)
    - unordered_multiset(C++11)   =>   collection of keys, hashed by keys(class template)
    - unordered_multimap(C++11)   =>   collection of key-value pairs, hashed by keys(class template)

### **Container adaptors**
Container adaptors provide a different interface for sequential containers.

    - stack   => adapts a container to provide stack (LIFO data structure)(class template)
    - queue   => adapts a container to provide queue (FIFO data structure)(class template)
    - priority_queue        =>  adapts a container to provide priority queue(class template)
    - flat_set(C++23)       =>  adapts a container to provide a collection of unique keys, sorted by keys(class template)
    - flat_map(C++23)       =>  adapts a container to provide a collection of key-value pairs, sorted by unique keys(class template)
    - flat_multiset(C++23)  =>  adapts a container to provide a collection of keys, sorted by keys(class template)
    - flat_multimap(C++23)  =>  adapts a container to provide a collection of key-value pairs, sorted by keys(class template)

![Unordered Associative Containers 1](https://media.geeksforgeeks.org/wp-content/uploads/20191111161536/Screenshot-from-2019-11-11-16-13-18.png)

![Unordered Associative Containers 2](https://media.geeksforgeeks.org/wp-content/uploads/20191111161627/Screenshot-from-2019-11-11-16-15-07.png)

[More C++ Containers Information](https://en.cppreference.com/w/cpp/container)

# Data Structure and Algorithm Lab
If you love this repository you can join with me on Data Structure and Algorithm Lab.

Together we will research and create useful things for the community.

[Discord](https://discord.gg/N8CrS3Ccsp)