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

    def insert_at_beg(self):
        pass
    def insert_at_end(self):
        pass
    def insert_at_n(self):
        pass
    def delete_from_beg(self):
        pass
    def delete_from_end(self):
        pass
    def delete_from_n(self):
        pass
    def display(self):
        pass
    def reverse(self):
        pass
    def print_reverse(self):
        pass

if __name__ == '__main__':
    li = SinglyCircularLinkedList()








