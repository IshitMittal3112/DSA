#include <iostream>
using namespace std;
void Print_array(int *arr,int n)
{
    int i;
    cout << "Array is:\n";
    for (i = 0; i <= n; i++)
    {
        cout << arr[i];
        cout << "\t";
    }
}


void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


void Bubble_Sort(int *arr,int n)
{
    int i,j;
    for (i=0;i<=n;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main()
{
    int arr[]={64,34,25,12,22,11,90};
    int size=sizeof(arr)/sizeof(arr[0]);
    int n=size-1;
    Bubble_Sort(arr,n);
    Print_array(arr,n);
    return 0;
}