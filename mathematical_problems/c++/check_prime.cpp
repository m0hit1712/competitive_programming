#include <bits/stdc++.h>
using namespace std;

bool naive_approach(int num){
        if (num == 1){
                return false;
        }
        else{
                for(int i=2; i<num; i++){
                        if (num%i==0){
                                return false;
                        }
                }
                return true;
        }
}

bool optimal_approach(int num){
        if(num==1){
                return false;
        }
        else{
                for(int i=2; i*i<=num; i++){
                        if(num%i==0){
                                return false;
                        }
                }
                return true;
        }
}

bool most_efficient_appraoch(int num){
        if (num == 1)
        {
                return false;
        }
        if (num==2 || num==3){
                return true;
        }
        if (num%2==0 || num%3==0){
                return false;
        }
        for (int i=5; i*i<=num; i+6){
                if(num%i==0 || num%(i+2)==0){
                        return false;
                }
                return true;
        }
}

int main(){
        int num = 7;
        printf("naive is %d prime: %s\n", num, naive_approach(num) ? "True" : "False");
        printf("somehow optimal is %d prime: %s\n", num, optimal_approach(num) ? "True" : "False");
        printf("most efficient is %d prime: %s\n", num, most_efficient_appraoch(num) ? "True" : "False");
}


