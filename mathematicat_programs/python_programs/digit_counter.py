from sys import stdin, stdout
import math
def iterative_approach(number):
        counter = 0
        while number%10:
                number = int(number/10)
                counter += 1
        return counter

def recursive_approach(number):
        if not number:
                return 0
        return recursive_approach(int(number/10))+1

def logarithmic_approach(number):
        return math.floor(math.log(number, 10))+1

def to_string_approach(number):
        return len(str(number))

if __name__=="__main__":
        #number = stdin.readline()
        number = 48564561265456894569454616456426165465465465465
        stdout.write("iter: "+str(iterative_approach(number))+"\n")
        stdout.write("recur: "+str(recursive_approach(number))+"\n")
        stdout.write("log: "+str(logarithmic_approach(number))+"\n")
        stdout.write("to_str: "+str(to_string_approach(number))+"\n")


