#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

void SieveOfEratosthenes(int n, string opt)
{
        int range = n;
        if (opt != "upto")
        {
                n = MAX;
        }
        bool primes[n + 1];
        // memset is used to fill all the array with a single value
        memset(primes, true, sizeof(primes));
        for (int i=2; i*i <= n; i++)
        {
                if (primes[i] == true)
                {
                        for (int j=i*i; j<=n; j+=i)
                        {
                                primes[j] = false;
                        }
                }
        }
        printf("prime numbers: ");
        int counter=0;
        for(int i=2;i<=n;i++)
        {
                if(primes[i])
                {
                        printf("%d ",i);
                        counter++;
                        if (counter>=range)
                                break;
                }
        }
        printf("\n");
}
bool normal_is_prime(int n)
{
        if (n<=1) return false;
        for (int i=2;i<n;i++)
        {
                if(n%i==0)
                {
                        return false;
                }
        }
        return true;
}
bool optimal_is_prime(int n)
{
        if (n <= 1)  return false;
        if (n == 2) return true;
        if (n%2 == 0) return false;

        for (int i = 3; i < n/2; i+2)
        {
                if (n % i == 0)
                {
                        return false;
                }
        }
        return true;
}
void normal_iter_prime_series(int n)
{
        printf("prime numbers: ");
        for(int i=2; i<n; i++)
        {
                if (optimal_is_prime(i))
                {
                        printf("%d ",i);
                }
        }
        printf("\n");
}
int main()
{
        SieveOfEratosthenes(60,"upto");  // if you will pass 'upto' it will give the prime numbers less than the passed n      // time complexity O(n)
        SieveOfEratosthenes(6, "first 6"); // if you pass anything in the string it will give the first n prime number          // time complexity O(MAX)
        printf("prime: %s\n", normal_is_prime(8)? "True" : "False");    //time complexity O(n)
        printf("prime: %s\n", optimal_is_prime(7) ? "True" : "False");  //time complexity O(n/4)
        normal_iter_prime_series(30); // it takes so much time if you will pass more than 30 your program will stuck         //time complexity O(n*(n/2)) 
        return 0;
}

/*
HERE ARE SOME ALGORITHES THAT CAM ALSO BE USED TO GET OR CHECK PRIME NUMBER

https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method
https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/
https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
https://www.geeksforgeeks.org/primality-test-set-4-solovay-strassen/
https://www.geeksforgeeks.org/primality-test-set-5using-lucas-lehmer-series/


most efficient algorithm is Sieve Of Eratosthenes 
as it actually has the complexity O(n) which is less than the complexities 
of all other algorithms.
*/




