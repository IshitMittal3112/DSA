#include <iostream>
using namespace std;
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int arr[3][3]={{1,0,0},{0,2,0},{0,0,3}};
    int size=sizeof(arr[0])/sizeof(arr[0][0]);
    int diag[size];
    int i;
    for ( i=0;i<size;i++)
    {
        diag[i]=arr[i][i];
    }
    Display(diag,size);
   return 0;
}