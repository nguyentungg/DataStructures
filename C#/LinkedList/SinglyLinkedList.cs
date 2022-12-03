internal class Node
{
    internal int data;
    internal Node next;
    public Node(int d)
    {
        data = d;
        next = null;
    }
}

internal class SingleLinkedList
{
    internal Node head;
}

internal class SinglyLinkedListHelper
{
    //Insert data at front of the Linked List 
    internal void InsertFront(SingleLinkedList singlyList, int new_data)
    {
        Node new_node = new Node(new_data);
        new_node.next = singlyList.head;
        singlyList.head = new_node;
    }

    //Insert data at the end of Linked List
    internal void InsertLast(SingleLinkedList singlyList, int new_data)
    {
        Node new_node = new Node(new_data);
        if (singlyList.head == null)
        {
            singlyList.head = new_node;
            return;
        }
        Node lastNode = GetLastNode(singlyList);
        lastNode.next = new_node;
    }

    internal Node GetLastNode(SingleLinkedList singlyList)
    {
        Node temp = singlyList.head;
        while (temp.next != null)
        {
            temp = temp.next;
        }
        return temp;
    }

    //Insert data after a given node of Linked List
    internal void InsertAfter(Node prev_node, int new_data)
    {
        if (prev_node == null)
        {
            Console.WriteLine("The given previous node Cannot be null");
            return;
        }
        Node new_node = new Node(new_data);
        new_node.next = prev_node.next;
        prev_node.next = new_node;
    }

    //Delete a node from Linked List using a given key value
    internal void DeleteNodebyKey(SingleLinkedList singlyList, int key)
    {
        Node temp = singlyList.head;
        Node prev = null;
        if (temp != null && temp.data == key)
        {
            singlyList.head = temp.next;
            return;
        }
        while (temp != null && temp.data != key)
        {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null)
        {
            return;
        }
        prev.next = temp.next;
    }

    //Reverse a Singly Linked list
    public void ReverseLinkedList(SingleLinkedList singlyList)
    {
        Node prev = null;
        Node current = singlyList.head;
        Node temp = null;
        while (current != null)
        {
            temp = current.next;
            current.next = prev;
            prev = current;
            current = temp;
        }
        singlyList.head = prev;
    }
}