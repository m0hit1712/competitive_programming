// FIND LCM

//a x b = LCM(a, b) * GCD(a, b)
//LCM(a, b) = (a x b) / GCD(a, b)
/*
A simple solution is to find all prime factors of both numbers, 
then find union of all factors present in both numbers.Finally, return the product of elements in union.
*/
#include<iostream>
using namespace std;

long long naive_appraoch(int a, int b){
        long long ma = max(a, b);
        for (int i=ma; i<=a*b; i++){
                if (i%a==0 && i%b==0){
                        return i;
                }
        }
        return ma;
}

long long greatest_common_divisor(long long int a, long long int b)
{
        if (b==0)
        {
                return a;
        }
        return greatest_common_divisor(b, a % b);
}

long long recursive_approach(int a, int b)
{       
        return (a / greatest_common_divisor(a, b)) * b;
}

int main()
{
        printf("recursive appraoch GCD formula LCM: %d\n", recursive_approach(24, 42));
        printf("naive appraoch LCM: %d\n", naive_appraoch(24, 42));
}
