/*      NOTE******
this program can only calculate factorials up to 12
because the length of the factorial will exceed the length of unsigned long long int 
program will return a garbage value
*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i <= b; i++)
typedef long long int ll;
typedef unsigned long long int ull;
ull iterative_approach(int number)
{
        if (number == 0)
        {
                return 1;
        }
        ll fact = 1; 
        while(number != 1)
        {
                fact *= number; 
                number--;
        }
        return fact;
}
ull recursive_approach(int number)
{
        if(number==1 || number==0)
        {
                return 1;
        }
        return number*recursive_approach(number-1);
}
int main()
{
        int number=13;
        //scanf("Enter number: %d", &number);
        printf("iter factorial: %d\n", iterative_approach(number));
        printf("recur factorial: %d\n", recursive_approach(number));
}


