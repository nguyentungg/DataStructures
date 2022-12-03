using System;
using System.Collections.Generic;

class LinkedList
{
    // Main Method
    static public void Main()
    {
        // LinkedList: AddFirst(), AddLast(), AddBefore(), AddAfter(),
        //             Remove(), RemoveFirst(), RemoveLast(), 
        //             Find(), FindLast(), 
        //             Clear(), Contains(), CopyTo(),
        //             GetEnumerator(), OnDeserialization(Object), GetObjectData(SerializationInfo, StreamingContext)
        
        // LinkedListNode: List, Next, Previous, Value, ValueRef

        // Creating a linkedlist using LinkedList class
        LinkedList<String> my_list = new LinkedList<String>();

        // Adding elements in the LinkedList Using AddFirst() method
        my_list.AddFirst("Zoya");

        // Adding elements in the LinkedList Using AddLast() method
        my_list.AddLast("Rohan");
        my_list.AddLast("Juhi");
        my_list.AddLast("Shilpa");

        // Find the node in the LinkedList
        LinkedListNode<string> currentFind = sentence.Find("Shilpa");
        LinkedListNode<string> currentFindLast = sentence.FindLast("Shilpa");

        // Adding elements in the LinkedList Using AddBefore() method
        my_list.AddBefore(current, "Rohit");

        // Adding elements in the LinkedList Using AddAfter() method
        my_list.AddAfter(currentFindLast, "Rohan");

        // Accessing the elements of Linkedlist
        foreach (string str in my_list)
        {
            Console.WriteLine(str);
        }

        // Output:
        // Zoya
        // Rohan
        // Juhi
        // Rohit
        // Shilpa
        // Rohan

        // Remove(LinkedListNode) first value
        my_list.Remove(my_list.First);

        // Output:
        // Rohan
        // Juhi
        // Rohit
        // Shilpa
        // Rohan

        // Remove(T) a specific value
        my_list.Remove("Rohit");

        // Output:
        // Rohan
        // Juhi
        // Shilpa
        // Rohan

        // Remove first value in LinkedList
        my_list.RemoveFirst();
        
        // Output:
        // Juhi
        // Shilpa
        // Rohan

        // Remove last value in LinkedList
        my_list.RemoveLast();

        // Output:
        // Juhi
        // Shilpa

        my_list.Clear();

        my_list.Count();

        my_list.Contains("Shilpa");

        // Create an array with the same number of elements as the linked list.
        string[] newArray = new string[sentence.Count];
        my_list.CopyTo(newArray, 0);
    }
}
