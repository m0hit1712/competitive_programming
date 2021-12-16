def readintlist(): return [int(i) for i in input().split()]
def stdint(): return int(input())

def linear_search(li, start, end, K):
        for i in range(start, end+1):
                if li[i] == K:
                        return i
        return -1

def jump_search(li, N, K):
        M = int(N ** 0.5)
        for i in range(0, N, M):
                if K == li[i]:
                        return i
                elif K < li[i]:
                        return linear_search(li, i-M,i, K)


if __name__ == '__main__':
        N = stdint()
        li = readintlist()
        K = stdint()

        ind = jump_search(li, N, K)
        print(f"{K} found at index {ind} in list (recursive)") if ind>=0 else print(f"{K} not found in list")
