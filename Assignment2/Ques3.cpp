#include <iostream>
using namespace std;
int MissingNum1(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i+1]!=arr[i]+1)
        {
            return arr[i]+1;
            break;
        }
        else
        {
            continue;
        }
    }
    return -1;
}
int MissingNum2(int *arr,int n)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]!=mid+1 && arr[mid-1]==mid)
        {
            return mid+1;
        }
        else if(arr[mid]==mid+1)
        {
            l=mid+1;
        }
        else 
        {
            h=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int num=MissingNum1(arr,size);    
    cout<<"Missing Number is:"<<num;
    return 0;
}
