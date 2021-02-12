#include <bits/stdc++.h>
using namespace std;
void multiply_number(int number, int arr[], int &arr_size)
{
        int carry = 0;
        for (int i=0;i<arr_size;i++)
        {
                int product = arr[i] * number + carry;
                arr[i] = product % 10;
                carry = product / 10;
        }       
        while (carry)
        {
                arr[arr_size] = carry%10;
                carry /= 10;
                arr_size++;
        }
}
void large_factorial(int number)
{
        int arr[1000];
        arr[0] = 1;
        int arr_size = 1;
        for (int i=2;i<=number;i++)
        {
                multiply_number(i, arr, arr_size);
        }
        for (int i=arr_size-1; i>=0;i--)
        {
                printf("%d",arr[i]);
        }
}
int main()
{
        int number = 100;
        printf("large factorial: ");
        large_factorial(number);
}



