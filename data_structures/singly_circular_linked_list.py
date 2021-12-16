import sys
stdwrite = lambda line: sys.stdout.write(line)


class SinglyCircularLinkedList:
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
        if not SinglyCircularLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            new.set_next(new)
            SinglyCircularLinkedList.__head = new
        else:
            new = self.__Node()
            new.set_data(data)
            new.set_next(SinglyCircularLinkedList.__head)
            temp = new.get_next().get_next()
            while temp.get_next() != SinglyCircularLinkedList.__head:
                temp = temp.get_next()
            SinglyCircularLinkedList.__head = new
            temp.set_next(SinglyCircularLinkedList.__head)

    def insert_at_end(self, data):
        if not SinglyCircularLinkedList.__head:
            new = self.__Node()
            new.set_data(data)
            new.set_next(new)
            SinglyCircularLinkedList.__head = new
        else:
            new = self.__Node()
            new.set_data(data)
            temp = SinglyCircularLinkedList.__head
            while temp.get_next() != SinglyCircularLinkedList.__head:
                temp = temp.get_next()
            temp.set_next(new)
            new.set_next(SinglyCircularLinkedList.__head)

    def insert_at_n(self, data, n):
        if not SinglyCircularLinkedList.__head:
            stdwrite("List is not create yet\n")
            return False
        elif n == 0:
            self.insert_at_beg(data)
        else:
            counter = 0
            temp = SinglyCircularLinkedList.__head
            while temp:
                if counter == n:
                    if temp.get_next() == SinglyCircularLinkedList.__head:
                        self.insert_at_end(data)
                        return True
                    new = self.__Node()
                    new.set_data(data)
                    new.set_next(temp.get_next())
                    temp.set_next(new)
                    return True
                temp = temp.get_next()
                counter += 1
            stdwrite("This is index does not exist in the list\n")
            return False

    def delete_from_beg(self):
        if not SinglyCircularLinkedList.__head:
            stdwrite("List is already empty\n")
        else:
            temp = SinglyCircularLinkedList.__head.get_next()
            if SinglyCircularLinkedList.__head == temp:
                SinglyCircularLinkedList.__head = None
            else:
                new_head_after_node = SinglyCircularLinkedList.__head.get_next() 
                while temp.get_next() != SinglyCircularLinkedList.__head:
                    temp = temp.get_next()
                temp.set_next(new_head_after_node)
                SinglyCircularLinkedList.__head = new_head_after_node

    def delete_from_end(self):
        if not SinglyCircularLinkedList.__head:
            stdwrite("List is already empty\n")
        else:
            temp = SinglyCircularLinkedList.__head.get_next()
            if SinglyCircularLinkedList.__head == temp:
                SinglyCircularLinkedList.__head = None
            else:
                while temp.get_next().get_next() != SinglyCircularLinkedList.__head:
                    temp = temp.get_next()
                temp.set_next(SinglyCircularLinkedList.__head)

    def delete_from_n(self, n):
        if not SinglyCircularLinkedList.__head:
            stdwrite("List is already empty\n")
        elif n == 0:
            self.delete_from_beg()
        else:
            temp = SinglyCircularLinkedList.__head
            counter = 0
            while temp.get_next() != SinglyCircularLinkedList.__head:
                if counter == n-1:
                    temp.set_next(temp.get_next().get_next())
                    return True
                temp = temp.get_next()
                counter += 1
            stdwrite("This position does not exist\n")


    def display(self):
        if not SinglyCircularLinkedList.__head:
            stdwrite("List is empty\n")
        else:
            stdwrite("Singly Circular Linked List: head")
            temp = SinglyCircularLinkedList.__head.get_next()
            stdwrite(" -> " + str(SinglyCircularLinkedList.__head.get_data()))
            while temp != SinglyCircularLinkedList.__head:
                stdwrite(" -> "+str(temp.get_data()))
                temp = temp.get_next()
            stdwrite(" -> head \n")

    def __reverse(self, temp):
        if temp == SinglyCircularLinkedList.__head:
            return
        self.__reverse(temp.get_next())
        stdwrite(str(temp.get_data())+" <- ")

    def print_reverse(self):
        if not SinglyCircularLinkedList.__head:
            stdwrite("The list is empty\n")
        else:
            stdwrite("Reverse Singly Circular Linked List: head <- ")
            temp = SinglyCircularLinkedList.__head.get_next()
            self.__reverse(temp)
            stdwrite(str(SinglyCircularLinkedList.__head.get_data()))
            stdwrite(" <- head")


if __name__ == '__main__':
    li = SinglyCircularLinkedList()
    li.insert_at_end(1)
    li.insert_at_beg(3)
    li.insert_at_end(21)
    li.insert_at_end(4)
    li.insert_at_end(43)
    li.insert_at_end(1212)
    li.insert_at_n(454, 6)
    li.display()
    li.delete_from_beg()
    li.display()
    li.delete_from_end()
    li.display()
    li.delete_from_n(2)
    li.display()
    li.print_reverse()








