import sys
def stdwrite(line): return sys.stdout.write(line)


class DoublyLinkedList:
    class __Node:
        def __init__(self):
            self.previous = None
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

        def get_previous(self):
            return self.previous
        
        def set_previous(self, previous):
            self.previous = previous
    __head = None
    def insert_at_beg(self, data):
        if not DoublyLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            DoublyLinkedList.__head = new
            self.display()
        else:
            new = self.__Node()
            new.set_data(data)
            new.set_next(DoublyLinkedList.__head)
            DoublyLinkedList.__head.set_previous(new)
            DoublyLinkedList.__head = new
            self.display()

    def insert_at_end(self, data):
        if not DoublyLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            DoublyLinkedList.__head = new
            self.display()
        else:
            new = self.__Node()
            new.set_data(data)
            temp = DoublyLinkedList.__head
            while temp.get_next():
                temp = temp.get_next()
            new.set_previous(temp)
            temp.set_next(new)
            self.display()

    def insert_at_n(self, data, n):
        if not DoublyLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            DoublyLinkedList.__head = new
            self.display()
        elif n==0:
            self.insert_at_beg(data)
        else:
            counter = 0
            temp = DoublyLinkedList.__head
            while temp:
                if counter==n-1:
                    if not temp.get_next():
                        self.insert_at_end(data)
                        return True
                    new = self.__Node()
                    new.set_data(data)
                    new.set_next(temp.get_next())
                    new.set_previous(temp.get_next().get_previous())
                    temp.get_next().set_previous(new)
                    temp.set_next(new)
                    self.display()
                    return True
                temp = temp.get_next()
                counter += 1
            stdwrite("This is index does not exist in the list\n")
            return False

    def delete_from_beg(self):
        if not DoublyLinkedList.__head:
            stdwrite("List is already empty\n")
        else:
            DoublyLinkedList.__head = DoublyLinkedList.__head.get_next()
            self.display()

    def delete_from_end(self):
        if not DoublyLinkedList.__head:
            stdwrite("List is already empty\n")
        else:
            temp = DoublyLinkedList.__head
            if not temp.get_next():
                DoublyLinkedList.__head = None
            else:
                while temp.get_next().get_next():
                    temp = temp.get_next()
                temp.set_next(None)
                self.display()

    def delete_from_n(self, n):
        if not DoublyLinkedList.__head:
            stdwrite("List is already empty\n")
        elif n == 0:
            self.delete_from_beg()
        else:
            temp = DoublyLinkedList.__head
            counter = 0
            while temp:
                if counter == n-1:
                    try: 
                        if not temp.get_next().get_next():
                            self.delete_from_end()
                            return True
                        temp.get_next().get_next().set_previous(temp)
                        temp.set_next(temp.get_next().get_next())
                        self.display()
                        return True
                    except:
                        pass
                temp = temp.get_next()
                counter += 1
            stdwrite("This position does not exist\n")

    def display(self):
        if not DoublyLinkedList.__head:
            stdwrite("List is empty\n")
        else:
            stdwrite("Doubly Linked List: head")
            temp = DoublyLinkedList.__head
            while temp:
                stdwrite(" <-> "+str(temp.get_data()))
                temp = temp.get_next()
            stdwrite("\n")

    def __reverse(self, temp):
        if temp == None:
            return
        self.__reverse(temp.get_next())
        stdwrite("<- "+str(temp.get_data())+" ")

    def print_reverse(self):
        if not DoublyLinkedList.__head:
            stdwrite("The list is empty\n")
        else:
            stdwrite("Reverse Linked List: ")
            temp = DoublyLinkedList.__head
            self.__reverse(temp)
            stdwrite("<-> head")


if __name__=="__main__":
    li = DoublyLinkedList()
    li.insert_at_beg(4)
    li.insert_at_beg(5)
    li.insert_at_beg(41)
    li.insert_at_end(7)
    li.insert_at_n(10, 1)
    li.delete_from_beg()
    li.delete_from_end()
    li.delete_from_n(2)
    li.print_reverse()




