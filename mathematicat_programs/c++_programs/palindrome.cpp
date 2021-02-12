#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for (int i=a;i<=b;i++)
bool iterative_approach(string st)
{
        int st_len = st.length();
        loop(i, 0, st_len/2)
        {
                if(st[i] != st[st_len-i-1])
                {
                        return false;
                }
        }
        return true;
}
bool recursive_approach(string st,int start,int end)
{
        if (start>=end)
        {
                return true;
        }
        if(st[start] == st[end])
        {
                return recursive_approach(st, start+1, end-1);
        }
        return false;
}
int main()
{
        string st="123456789987654321";
        //scanf("Enter string: %s", &st);
        printf("result: %s\n",iterative_approach(st) ? "True" : "False");
        printf("result: %s\n", recursive_approach(st, 0, st.length() - 1) ? "True" : "False");
}

