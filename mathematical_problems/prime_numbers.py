import sys
stdint =lambda: int(sys.stdin.readline())
stdwrite =lambda line: sys.stdout.write(line)  
MAX = 1000000

def sieve_of_eratosthenes(n, opt):
        r = n
        if opt != "upto":
                n = MAX
        primes = [True for i in range(n+1)]
        p = 2
        while p*p <= n:
                if primes[p]:
                        for i in range(p*2, n+1, p):
                                primes[i] = False
                p += 1
        stdwrite("prime numbers: ")
        ctr = 0
        for i in range(2, n+1):
                if primes[i]:
                        stdwrite(str(i)+" ")
                        ctr += 1
                        if ctr >= r:
                                break
        stdwrite("\n")

def normal_is_prime(n):
        if n <= 1: return False
        for i in range(2,n):
                if n%i==0:
                        return False
        return True

def optimal_is_prime(n):
        if n <= 1: return False
        if n == 2: return True
        if n%2 == 0: return True
        for i in range(3, int(n/2)):
                if n%i==0:
                        return False
        return True

def normal_iter_prime_series(n):
        stdwrite("prime numbers: ")
        for i in range(2, n):
                if optimal_is_prime(i):
                        stdwrite(str(i)+" ")
        stdwrite("\n")


if __name__ == "__main__":
        sieve_of_eratosthenes(504, "upto")
        sieve_of_eratosthenes(50, "first 50")
        stdwrite(str(normal_is_prime(4177)) +"\n")
        stdwrite(str(optimal_is_prime(4177)) +"\n")
        normal_iter_prime_series(45)


