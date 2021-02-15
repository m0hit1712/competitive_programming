import sys
stdwrite = lambda line: sys.stdout.write(line) 

class SinglyLinkedList:
    class __Node:
        def __init__(self):
            self.data = None
            self.next = None

        def set_data(self, data):
            self.data = data

        def get_data(self):
            return self.data

        def set_next(self, next):
            self.next = next

        def get_next(self):
            return self.next
    __head = None

    def insert_at_beg(self, data):
        if not SinglyLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            SinglyLinkedList.__head = new
        else:
            new = self.__Node()
            new.set_data(data)
            new.set_next(SinglyLinkedList.__head)
            SinglyLinkedList.__head = new
        self.display()

    def insert_at_end(self, data):
        if not SinglyLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            SinglyLinkedList.__head = new
        else:
            new = self.__Node()
            new.set_data(data)
            temp = SinglyLinkedList.__head
            while temp.get_next():
                temp = temp.get_next()
            temp.set_next(new)
        self.display()

    def insert_at_n(self, data, n):
        if not SinglyLinkedList.__head:
            stdwrite("List is not create yet\n")
            return False
        elif n==0:
            self.insert_at_beg(data)
        else:
            counter = 0
            temp = SinglyLinkedList.__head
            while temp:
                if counter==n-1:
                    if not temp.get_next():
                        self.insert_at_end(data)
                        return True
                    new = self.__Node()
                    new.set_data(data)
                    new.set_next(temp.get_next())
                    temp.set_next(new)
                    self.display()
                    return True
                temp = temp.get_next()
                counter += 1
            stdwrite("This is index does not exist in the list\n")
            return False

    def delete_from_beg(self):
        if not SinglyLinkedList.__head:
            stdwrite("List is already empty\n")
        else:
            SinglyLinkedList.__head = SinglyLinkedList.__head.get_next()
            self.display()
    def delete_from_end(self):
        if not SinglyLinkedList.__head:
            stdwrite("List is already empty\n")
        else:
            temp = SinglyLinkedList.__head
            if not temp.get_next():
                SinglyLinkedList.__head = None
            else:
                while temp.get_next().get_next():
                    temp = temp.get_next()
                temp.set_next(None)
                self.display()

    def delete_from_n(self, n):
        if not SinglyLinkedList.__head:
            stdwrite("List is already empty\n")
        elif n==0:
            self.delete_from_beg()
        else:
            temp = SinglyLinkedList.__head
            counter = 0 
            while temp:
                if counter == n-1:
                    try: 
                        temp.set_next(temp.get_next().get_next())
                        self.display()
                        return True
                    except:
                        stdwrite("This position does not exist\n")
                        return False
                temp = temp.get_next()
                counter += 1
            stdwrite("This position does not exist\n")

    def display(self):
        if not SinglyLinkedList.__head:
            stdwrite("List is empty\n")
        else:
            stdwrite("Singly Linked List: head")
            temp = SinglyLinkedList.__head
            while temp:
                stdwrite(" -> "+str(temp.get_data()))
                temp = temp.get_next()
            stdwrite("\n")
    def __reverse(self, temp):
        if temp==None:
            return 
        self.__reverse(temp.get_next())
        stdwrite("<- "+str(temp.get_data())+" ")

    def print_reverse(self):
        if not SinglyLinkedList.__head:
            stdwrite("The list is empty\n")
        else:
            stdwrite("Reverse Linked List: ")
            temp = SinglyLinkedList.__head
            self.__reverse(temp)
            stdwrite("<- head")

if __name__ == '__main__':
    li = SinglyLinkedList()
    li.insert_at_beg(4)
    li.insert_at_beg(5)
    li.insert_at_beg(41)
    li.insert_at_end(7)
    li.insert_at_n(10, 2)
    li.delete_from_beg()
    li.delete_from_end()
    li.delete_from_n(2)
    li.print_reverse()
