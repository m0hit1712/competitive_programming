import sys
readintlist = lambda: [int(i) for i in sys.stdin.readline().split()]
stdint = lambda: int(sys.stdin.readline())

def rotate_array(arr, n, d):
        arr = arr[d:].extend(arr[0:d])
        return arr


if __name__ == "__main__":
        print("Enter space saperated array: ", end="")
        li = readintlist()
        print("Entter rotation index: ", end="")
        d = stdint()
        print(rotate_array(li, len(li), d))





