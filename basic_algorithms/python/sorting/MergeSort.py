import sys
sys.setrecursionlimit(1500)

def merge(arr, l, m, r): 
    p, q = l, m+1
    temp = []
    for i in range(l, r+1):
        if p > m:
            temp.append(arr[q]) 
            q+=1
        elif q > r:
            temp.append(arr[p])
            p+=1
        elif arr[p] < arr[q]:
            temp.append(arr[p])
            p+=1
        else:
            temp.append(arr[q])
            q+=1

    for i in range(0, len(temp)):
        arr[l] = temp[i]
        l+=1

def mergeSort(arr, l, r):
    if l<r:
        mid = (l+r)//2
        mergeSort(arr, l, mid)
        mergeSort(arr, mid+1, r)
        merge(arr, l, mid, r)


if __name__ == '__main__':
    n=int(input())
    arr = list(map(int, input().split()))
    mergeSort(arr, 0, n-1)
    for i in arr:
        print(i, end=' ')
    print()

