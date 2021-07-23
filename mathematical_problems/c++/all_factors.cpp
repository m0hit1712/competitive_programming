#include <bits/stdc++.h>
using namespace std;

void naive_approach(int num){
        printf("All factors of %d: ", num);
        for (int i=1; i<=num; i++){
                if (num%i==0){
                        printf("%d ", i);
                }
        }
        printf("\n");   
}

void optimal_approach(int num){
        printf("All factors of %d: ", num);
        for (int i = 1; i*i < num; i++){
                if (num%i==0){
                        printf("%d ", i);
                        if(i != num/i){
                                printf("%d ", num/i);
                        }
                }
        }
        printf("\n");
}
void optimal_in_sorted_approach(int num){
        printf("All factors of %d: ", num);
        int i;
        for (i = 1; i * i < num; i++)
        {
                if (num % i == 0)
                {
                        printf("%d ", i);
                }
        }
        for( ;i>=1; i--){
                if (num%i == 0)
                {
                        printf("%d ", num/i);
                }
        }
        printf("\n");
}



int main(){
        naive_approach(450);
        optimal_approach(450);
        optimal_in_sorted_approach(450);
}