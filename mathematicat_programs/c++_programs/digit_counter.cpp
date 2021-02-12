#include <bits/stdc++.h>
using namespace std;
//#define loop(i, a, b) for (int i = a; i <= b; i++)
typedef long long int ll;

int iterative_approach(ll digit)
{
        int counter=0;
        while(digit%10)
        {
                counter++;
                digit /=10;
        }
        return counter;
}
int recursive_approach(ll digit)
{
        if (digit==0)
        {
                return 0;
        }
        return recursive_approach(digit/10)+1;
}
int logarithemic_approach(ll digit)
{
        return floor(log10(digit)+1);
}
int to_string_approach(ll digit)
{
        string number = to_string(digit);
        return number.size();
}
int main()
{
        ll number=144515545441454;
        printf("iter: %d\n", iterative_approach(number));
        printf("recur: %d\n", recursive_approach(number));
        printf("log: %d\n", logarithemic_approach(number));
        printf("to_str: %d", to_string_approach(number));
        return 0;
}

