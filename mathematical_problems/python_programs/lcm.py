from sys import stdin, stdout

def gcd(a, b):
        if b==0:
                return a
        return gcd(b, a%b)

def LCM(a, b):
        return int(a*b/gcd(a, b))

a = int(stdin.readline())
b = int(stdin.readline())

stdout.write("LCM: "+str(LCM(a, b))+"\n")
