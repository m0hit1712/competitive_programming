readintlist =lambda: [int(i) for i in input().split()]
stdint = lambda: int(input())

def recursive_approach(li, start, end, K):
        if end >= start:
                mid = start + (end-start)//2
                if li[mid] == K:
                        return mid
                elif K>li[mid]:
                        return recursive_approach(li, mid+1, end, K)
                else:
                        return recursive_approach(li, start, mid-1, K)
        return -1

def iterative_approach(li, N, K):
        start = 0
        end = N-1
        while end >= start:
                mid = start + (end-start)//2
                if li[mid] == K:
                        return mid
                elif K>li[mid]:
                        start = mid+1
                else:
                        end = mid-1
        return -1


if __name__ == '__main__':
        N = stdint()
        li = readintlist()
        K = stdint()

        ind = recursive_approach(li, 0, N-1, K)
        print(f"{K} found at index {ind} in list (recursive)") if ind>=0 else print(f"{K} not found in list")
        
        ind = iterative_approach(li, N, K)
        print(f"{K} found at index {ind} in list (iterative)") if ind>=0 else print(f"{K} not found in list")








