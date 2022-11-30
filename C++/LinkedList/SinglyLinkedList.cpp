#include <iostream>
#include <cstdlib>

struct Node {
    int value;
    struct Node * next;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void createNode(int value)
    {
        Node *temp = new Node;
        temp->value = value;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {	
            tail->next = temp;
            tail = temp;
        }
    }

    void pushNode(int value) {
        Node * new_node;
        new_node = new Node;

        new_node->value = value;
        new_node->next = head;

        head = new_node;
    }
    
    int pop() {
        int retval = 0;
        Node * next_node = nullptr;

        next_node = head->next;
        retval = head->value;
        delete head;
        head = next_node;

        return retval;
    }

    int removeLast() {
        int retval = 0;
    /* if there is only one item in the list, remove it */
        if (head->next == nullptr) {
            retval = head->value;
            delete head;
            return retval;
        }

    /* get to the second to last node in the list */
        Node * current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

    /* now current points to the second to last item of the list, so let's remove current->next */
        retval = current->next->value;
        delete current->next;
        current->next = nullptr;
        return retval;
    }


    void removeByValue(int value) {
        Node *previous;
        Node *current;

        if (head == nullptr) {
            return;
        }

        if (head->value == value) {
            return;
            pop();
        }

        previous = current = head->next;
        while (current) {
            if (current->value == value) {
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current  = current->next;
        }
    }

    void printList() {
        Node * current = head;

        while (current != nullptr) {
            std::cout << current->value << std::endl;
            // std::cout << "\r" << current->value;
            current = current->next;
        }
    }

private:
    Node *head;
    Node *tail;
};


int main() {

    LinkedList linkedlist;

    linkedlist.pushNode(1);
    linkedlist.pushNode(3);
    linkedlist.pushNode(2);
    linkedlist.pushNode(5);

    linkedlist.removeByValue(3);

    linkedlist.printList();

    return 0;
}