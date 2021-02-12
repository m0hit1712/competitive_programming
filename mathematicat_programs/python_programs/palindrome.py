from sys import stdin, stdout

def iterative_approach(st):
        l = len(st)
        for i in range(0, int(l/2)):
                if st[i] != st[l-i-1]:
                        return False
        return True

def recursive_approach(st, start, end):
        if start >= end:
                return True
        if st[start] != st[end]:
                return False
        return recursive_approach(st, start+1, end-1)

def python_break_reverse_approach(st):
        l = len(st)
        if(l%2==0):
                if st[:int(l/2)] == st[::-1][:int(l/2)]:
                        return True
        else:
                if st[:int(l/2)-1] == st[::-1][:int(l/2)-1]:
                        return True
                pass
        return False
if __name__=="__main__":
        st = "123456789987654321"
        stdout.write("result: "+str(recursive_approach(st,0,len(st)-1))+"\n")
        stdout.write("result: "+str(iterative_approach(st))+"\n")
        stdout.write("result: "+str(python_break_reverse_approach(st))+"\n")



