#include <bits/stdc++.h>
using namespace std;

bool most_efficient_is_prime(int num)
{
        if (num == 1)
        {
                return false;
        }
        if (num == 2 || num == 3)
        {
                return true;
        }
        if (num % 2 == 0 || num % 3 == 0)
        {
                return false;
        }
        for (int i = 5; i * i <= num; i + 6)
        {
                if (num % i == 0 || num % (i + 2) == 0)
                {
                        return false;
                }
                return true;
        }
}

void prime_factors_naive_approach(int num){
        printf("(naive) prime factors of %d : ", num);
        for(int i=2;i<num;i++){
                if (most_efficient_is_prime(i) && num%i==0){
                        int x = i;
                        while (num % x == 0)
                        {
                                printf("%d ", i);
                                x = x * i;
                        }
                }
        }
        printf("\n");
}

int prime_factors_optimal_approach(int num){
        if (num == 1){
                return false;
        }
        printf("(optimal) prime factors of %d : ", num);
        for(int i=2; i*i <= num; i++){
                while(num%i==0){
                        printf("%d ", i);
                        num = num/i;
                }
        }
        if (num > 1)
        {
                printf("%d ", num);
        }
        printf("\n");
}
int most_efficient_prime_factors(int num){
        printf("(most efficient) prime factors of %d : ", num);
        if (num == 1){
                return false;
        }
        while (num % 2 == 0)
        {
                printf("%d ", 2);
                num = num / 2;
        }
        while (num % 3 == 0)
        {
                printf("%d ", 3);
                num = num / 3;
        }
        for(int i=5; i*i<=num; i+=6){
                while(num%i == 0){
                        printf("%d ", i);
                        num = num / i;
                }
                while(num%(i+2) == 0){
                        printf("%d ", i+2);
                        num = num / (i+2);
                }
        }
        if(num > 3){
                printf("%d ",num);
        }
        printf("\n");
}

int main()
{
        prime_factors_naive_approach(450);
        prime_factors_optimal_approach(450);
        most_efficient_prime_factors(450);
}