// FIND LCM

//a x b = LCM(a, b) * GCD(a, b)
//LCM(a, b) = (a x b) / GCD(a, b)
/*
A simple solution is to find all prime factors of both numbers, 
then find union of all factors present in both numbers.Finally, return the product of elements in union.
*/
#include<iostream>
using namespace std;

long long greatest_common_divisor(long long int a, long long int b)
{
        if (b==0)
        {
                return a;
        }
        return greatest_common_divisor(b, a % b);
}

long long LCM(int a, int b)
{
        return (a / greatest_common_divisor(a, b)) * b;
}

int main()
{
        int a=24,b=42;
        scanf("%d", &a);
        scanf("%d", &b);
        printf("LCM : %d", LCM(a,b));
}
