#include <bits/stdc++.h>
using namespace std;

long long naive_approach(int num, int power){
        long long res=1;
        while(power--){
                res *= num;
        }
        return res;
}

int recursive_efficient_approach(int num,int power){
        if (power == 0){
                return 1;
        }
        int temp = efficient_approach(num, power / 2);
        temp = temp*temp;
        if(power%2==0){
                return temp;
        }
        else{
                return temp*num;
        }
}

// Binary Exponentiation
int iterative_efficient_approach(int num, int power){

}

int main(){
        int num=2, power=8;
        printf("naive power %d of %d : %d\n", power, num, naive_approach(num, power));
        printf("efficient recursive Power %d of %d: %d\n", power, num, recursive_efficient_approach(num, power));
        printf("efficient iterative Power %d of %d: %d\n", power, num, iterative_efficient_approach(num, power));
}