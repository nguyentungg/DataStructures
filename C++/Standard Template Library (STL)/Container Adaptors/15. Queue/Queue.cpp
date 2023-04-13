//---------------------------------
// General Informations
//---------------------------------
// - FIFO context (first-in first-out), where elements are inserted and extracted only from one end of the container.
// - Elements are pushed into the "back" of the specific container and popped from its "front".
#include <queue> 

std::queue<int> q, qo;

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