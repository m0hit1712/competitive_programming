#since python has every datatype as a object so you can calculate the factorial of a large number with normal approaches
from sys import stdin, stdout
def iterative_approach(number):
        fact = 1
        while number:
                fact *= number
                number -= 1
        return fact

def recursive_approach(number):
        if number == 0 or number == 1:
                return 1
        return number*recursive_approach(number-1)

if __name__=="__main__":
        number = 100
        stdout.write("iter factorial: "+str(iterative_approach(number))+"\n")
        stdout.write("recur factorial: "+str(recursive_approach(number))+"\n")

