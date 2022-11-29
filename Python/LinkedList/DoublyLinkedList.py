#Python Implementation Doubly Linked Lists

class Node:

    def __init__(self, data):
        self.dataval = data
        self.nextval = None
        self.preval = None

class DLinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        if self.head is None:
            self.head = Node(data)
            self.lastnode = self.head
        else:
            temp = self.lastnode
            self.lastnode.nextval = Node(data)
            self.lastnode = self.lastnode.nextval
            self.lastnode.preval = temp

    def prepend(self,data):
        if self.head is None:
            self.head = Node(data)
        else:
            new_node = self.head
            new_node.preval = Node(data)
            self.head = new_node.preval
            self.head.nextval = new_node

    def removeAtStart(self):
        if self.head is None:
            return ('The Linked List is empty')
        
        temp = self.head
        self.head = self.head.nextval
        self.head.preval = None
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
            temp = curr_node.nextval
            temp.preval = new_node
            curr_node.nextval = new_node
            new_node.preval = curr_node

    def delete(self, index):
        curr_node = self.head
        i = 0

        while i < index and curr_node != None:
            curr_node = curr_node.nextval
            i+=1
        
        if(index == 0):
            self.removeAtStart()
        else:
            temp = curr_node.preval
            temp.nextval = curr_node.nextval
            temp = curr_node.nextval
            temp.preval = curr_node.preval
            del curr_node

    def reverse(self):
        next_node = self.head
        temp = None

        if self.head.nextval is None:
            return None

        else:
            while next_node is not None:
                temp = next_node.preval
                next_node.preval = next_node.nextval
                next_node.nextval = temp
                next_node = next_node.preval


            self.head.nextval = None
            self.head = temp.preval
            

    def displayAll(self):
        curr_node = self.head
        if self.head is None:
            print("Empty Linked List!")
        else:
            while curr_node is not None:
                print(curr_node.dataval, end=" ")
                curr_node = curr_node.nextval

myLinkedList = DLinkedList()

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