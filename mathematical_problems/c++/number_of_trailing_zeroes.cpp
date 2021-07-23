#include <bits/stdc++.h>
using namespace std;

int NumberofTralingZeroes_logn(int number){
        int result = 0;
        for (int i=5; i<=number; i*=5){
                result += (number/i);
        }
        printf("number of zeroes: %d\n", result);
}


int main(){
        int number = 100;
        NumberofTralingZeroes_logn(number);
}


