def bubbleSort(arr, n):
    for i in range(0, n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    bubbleSort(arr, n)
    for i in arr:
        print(i, end=' ')
    print()
