//---------------------------------
// General Informations
//---------------------------------
// - This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).
// - Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.

#include <queue> 

std::priority_queue<int> q, qo;

//---------------------------------
// General Operations
//---------------------------------

// Insert
q.push(value);
q.emplace ("value");        // tail

// Access head, tail
int head = q.front();       // head
int tail = q.back();        // tail

//Iterate
while (!q.empty())
{
   sum += q.front();
   q.pop();
}

// Size
unsigned int size = q.size();

// Remove
q.pop();

// Swap contents
q.swap(qo);

// Exchange contents of 2 queues
swap(q,qo);