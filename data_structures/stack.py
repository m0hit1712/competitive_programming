import sys
stdwrite = lambda line: sys.stdout.write(line)

class Stack:
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
    def __display_top(self):
        return Stack.__head.data

    def push(self, data):
        if not Stack.__head:
            new = self.__Node()
            new.set_data(data)
            Stack.__head = new
            stdwrite("[^] stack started\n")
            stdwrite("[+] new top: "+str(self.__display_top())+"\n")
            stdwrite("-----------------------------------\n")
        else:
            stdwrite("[-] previous top: " + str(self.__display_top())+"\n")
            stdwrite("[+] "+str(data)+" pushed\n")
            new = self.__Node()
            new.set_data(data)
            new.set_next(Stack.__head)
            Stack.__head = new
            stdwrite("[+] new top: "+str(self.__display_top())+"\n")
            stdwrite("-----------------------------------\n")

    def pop(self):
        if not Stack.__head:
            stdwrite("Stack is empty\n")
        else:
            stdwrite("[-] previous top: "+str(self.__display_top())+"\n")
            stdwrite("[-] "+str(self.__display_top())+" popped\n")
            try:
                Stack.__head = Stack.__head.get_next()
                stdwrite("[+] new top: "+str(self.__display_top())+"\n")
                stdwrite("-----------------------------------\n")
            except:
                Stack.__head = None
                stdwrite("-----------------------------------\n")


if __name__=='__main__':
    st = Stack()
    st.push(56)
    st.push(32)
    st.push(5452)
    st.push(3)
    st.pop()
    st.pop()
    st.pop()
    st.pop()
    st.pop()
    st.pop()

