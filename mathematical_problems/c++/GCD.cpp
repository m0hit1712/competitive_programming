#include <bits/stdc++.h>
using namespace std;

int naive_appraoch(int a, int b){
        int mi = min(a,b); 
        for (int i = mi; i >= 1; i--){
                printf("iter: mi=%d\n", mi);
                if(a%i==0 && b%i==0){
                        return i;
                }
        }

}

int uclidean_appraoch(int a, int b){
        while(a!=b){
                if (a>b){
                        a -= b;
                }
                else{
                        b -= a;
                }
                printf("iter: a=%d b=%d\n", a, b);
        }
        return a;
}

int recursive_appraoch(int a, int b){
        printf("recur: a=%d b=%d\n", a, b);
        if (b==0){
                return a;
        }
        else{
                return recursive_appraoch(b, a%b);
        }
}

int main(){
        printf("naive approach GCD: %d\n", naive_appraoch(8192,1024));
        printf("uclidean approach GCD: %d\n", uclidean_appraoch(8192, 1024));
        printf("recursive approach GCD: %d\n", recursive_appraoch(8192, 1024));
}