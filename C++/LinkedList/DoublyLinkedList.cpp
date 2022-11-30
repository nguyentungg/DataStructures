#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int value;
    struct Node * next;
    struct Node * prev;
};

class LinkedList
{
    public:

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
            length = 1;
        }

        // Add new value into the linked list
        void append(int value)
        {
            Node *new_node = new Node;
            new_node->value = value;
            new_node->next = nullptr;
            new_node->prev = nullptr;

            if (head == nullptr)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {	new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
            length++;
        }

        // Add new value to the first of linked list
        void prepend(int value) {
            Node * new_node;
            new_node = new Node;

            new_node->value = value;
            new_node->next = head;
            head->prev = new_node;

            head = new_node;
            length++;
        }

        // Print all the linked list value
        void printList() {
            Node * current_node = head;

            while (current_node != nullptr) {
                cout << "\r" <<current_node->value << ",";
                current_node = current_node->next;
            }
        }

        void insert(int index, int value){
            // Check for proper parameters
            if(index >= length){
                cout << "yes" << endl;
                return append(value);
            }

            Node * new_node = new Node;
            new_node->value = value;
            new_node->next = nullptr;
            Node * leader = traverseToIndex(index-1);
            Node * follower = leader->next;
            leader->next = new_node;
            new_node->prev = leader;
            new_node->next = follower;
            follower->prev = new_node;
            length++;

        }

        Node * traverseToIndex(int index){
            // Check parameters
            int counter = 0;
            Node * current_node = head;
            while(counter != index){
                current_node = current_node->next;
                counter++;
            }

            return current_node;
        }

        // Remote first value
        int pop() {
            int retval = 0;
            Node * next_node = nullptr;

            next_node = head->next;
            retval = head->value;            
            delete head;
            head = next_node;
            head->prev = nullptr;
            length--;

            return retval;
        }

        void remove(int index){
            // Check parameters
            Node * leader = traverseToIndex(index-1);
            Node * unwantedNode = leader->next;
            Node * follower = unwantedNode->next;
            leader->next = follower;
            follower->prev = leader;
            delete unwantedNode;
            length--;
        }

        void reverse(){
            if(head->next == nullptr){
                return;
            }
            Node * first = head;
            tail = head;
            Node * second = first->next;

            while(second != nullptr){
                Node * temp = second->next;
                second->next = first;
                first->prev = second;
                first = second;
                second = temp;
            }

            head->next = nullptr;
            head = first;

            return printList();
        }

    private:
        Node *head;
        Node *tail;
        int length;
};

int main() {

    LinkedList linkedlist;

    linkedlist.append(5);
    linkedlist.append(16);
    linkedlist.prepend(1);
    linkedlist.printList();
    cout << "\n--------------" << endl;
    linkedlist.insert(2, 99);
    linkedlist.printList();
    cout << "\n--------------" << endl;
    linkedlist.remove(2);
    linkedlist.printList();
    cout << "\n--------------" << endl;
    linkedlist.pop();
    linkedlist.printList();
    cout << "\n--------------" << endl;
    linkedlist.reverse();

    return 0;
}