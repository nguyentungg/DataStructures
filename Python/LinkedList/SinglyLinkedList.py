#Python Implementation Singly Linked Lists

class Node:

    def __init__(self, data):
        self.dataval = data
        self.nextval = None 

class SLinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        if self.head is None:
            self.head = Node(data)
            self.lastnode = self.head
        else:
            self.lastnode.nextval = Node(data)
            self.lastnode = self.lastnode.nextval

    def prepend(self,data):
        if self.head is None:
            self.head = Node(data)
        else:
            new_node = self.head
            self.head = Node(data)
            self.head.nextval = new_node

    def removeAtStart(self):
        if self.head is None:
            return ('The Linked List is empty')
        
        temp = self.head
        self.head = self.head.nextval
        del temp

    def insert(self,data,index):
        curr_node = self.head
        i = 1

        while i < index  and curr_node != None:
            curr_node = curr_node.nextval
            i+=1

        if index == 0:
            self.prepend(data)
        else:
            new_node = Node(data) 
            new_node.nextval = curr_node.nextval
            curr_node.nextval = new_node

    def delete(self, index):
        curr_node = self.head
        i = 0
        prev_node = None

        while i < index and curr_node != None:
            prev_node = curr_node
            curr_node = curr_node.nextval
            i+=1
        
        if(index == 0):
            self.removeAtStart()
        else:
            prev_node.nextval = curr_node.nextval
            del curr_node

    def reverse(self):
        curr_node = self.head
        next_node = self.head.nextval

        if self.head.nextval is None:
            return None

        else:
            while next_node is not None:
                temp = next_node.nextval 
                next_node.nextval = curr_node
                curr_node = next_node
                next_node = temp

            self.head.nextval = None
            self.head = curr_node

    def displayAll(self):
        curr_node = self.head
        if self.head is None:
            print("Empty Linked List!")
        else:
            while curr_node is not None:
                print(curr_node.dataval, end=" ")
                curr_node = curr_node.nextval

myLinkedList = SLinkedList()

myLinkedList.append(5)

myLinkedList.append(10)

myLinkedList.append(22)

myLinkedList.append(7)

myLinkedList.prepend(26)

myLinkedList.prepend(13)

myLinkedList.insert(17, 2)

myLinkedList.delete(2)

myLinkedList.insert(33, 4)

print('Linked List:', end=" ")
myLinkedList.displayAll()

print('')

print('Reversed Linked List:', end=" ")

myLinkedList.reverse()

myLinkedList.displayAll()