readintlist =lambda: [int(i) for i in input().split()]
stdint = lambda: int(input())


def linear_search(li, n, k):
        for i in range(n):
                if li[i] == k:
                        return i
        return -1

if __name__=='__main__':
        N = stdint()
        li = readintlist()
        K = stdint()
        ind = linear_search(li, N, K)
        print(f"{K} found at index {ind} in list") if ind>=0 else print(f"{K} not found in list")















