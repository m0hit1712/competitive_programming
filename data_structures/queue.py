import sys
stdwrite = lambda line: sys.stdout.write(line)

class Queue:
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

    def display(self):
        if not Queue.__head:
            stdwrite("Queue is empty\n")
        else:
            stdwrite("Queue: peek")
            temp = Queue.__head
            while temp:
                stdwrite(" -> "+str(temp.get_data()))
                temp = temp.get_next()
            stdwrite("\n")

    def enqueue(self, data):
        if not Queue.__head:
            new = self.__Node()
            new.set_data(data)
            Queue.__head = new
        else:
            new = self.__Node()
            new.set_data(data)
            temp = Queue.__head
            while temp.get_next():
                temp = temp.get_next()
            temp.set_next(new)
        self.display()

    def dequeue(self):
        if not Queue.__head:
            stdwrite("Queue is already empty\n")
        else:
            Queue.__head = Queue.__head.get_next()
            self.display()


if __name__ == '__main__':
    q = Queue()
    q.enqueue(1)
    q.enqueue(12)
    q.enqueue(32)
    q.enqueue(43)
    q.enqueue(232)
    q.enqueue(43252)
    q.dequeue()
    q.dequeue()






