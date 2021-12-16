import sys
sys.setrecursionlimit(1500)

def partition(arr, low, high):
    pivot = arr[low]
    i = low+1

    for j in range(low+1, high+1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i+=1

    arr[low], arr[i-1] = arr[i-1], arr[low]
    return i-1


def quickSort(arr, low, high):
    if low < high:
        pivot_pos = partition(arr, low, high)
        quickSort(arr, low, pivot_pos-1)
        quickSort(arr, pivot_pos+1, high)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    quickSort(arr, 0, n-1)
    for i in arr:
        print(i, end=' ')
    print()





