#include <iostream>
using namespace std;
int Binary_Search(int *arr,int n,int num)
{
    int mid;
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr[mid]==num)
        {
            return mid+1;
        }
        else if(arr[mid]>num)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<num<<"is Not Found";
    return -1;

}
int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr) / sizeof(arr [0]);
    int num;
    cout<<"Enter the Number You Want to Find:";
    cin>>num;
    int target=Binary_Search(arr,n,num);
    cout<<num<<"is found at:"<<target<<"th position";
    return 0;
}