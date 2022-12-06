#include <iostream>
#include <queue>

using namespace std;

class MyPriorityQueue
{

public:
    void MinHeap()
    {
        // Creates a min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(5);
        pq.push(1);
        pq.push(10);
        pq.push(30);
        pq.push(20);

        // One by one extract items from min heap
        while (pq.empty() == false)
        {
            cout << pq.top() << " ";
            pq.pop();
        }

    // Output: 
    // 1 5 10 20 30 
    }

    void MaxHeap()
    {
        // Creates a max heap
        priority_queue<int> pq;
        pq.push(5);
        pq.push(1);
        pq.push(10);
        pq.push(30);
        pq.push(20);

        // One by one extract items from max heap
        while (pq.empty() == false)
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    // Output
    // 30 20 10 5 1 
    }
};

int main()
{
    MyPriorityQueue mpq = MyPriorityQueue();

    return 0;
}

