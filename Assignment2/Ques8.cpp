#include <iostream>
#include <unordered_map>
using namespace std;

int CountDistinct(int *arr, int n){
    int cnt=1;
    if(n=0) return 0;
    for(int i=1; i<n; i++){
        bool appeared=false;
        for(int j=0; j<i; j++){
            if(arr[i] == arr[j]){
                appeared=true;
                break;
            }
            
            }
            if(!appeared){
                cnt++;
        }
    }
    return cnt;
    //Time Complexity: O(N^2)
    //Space Complexity: O(1)
}

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}


void Bubble_Sort(int *arr,int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int CountDistinct2(int *arr, int n){
    int cnt=1;
    
    Bubble_Sort(arr, n);
    
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            cnt++;
        }
    }
    return cnt;
    //Time Complexity: O(N^2)
    //Can Be Optimized to (N*log(N)) Using Merge Sort in place of Bubble Sort.
    //Space Complexity: O(1)
}

int CountDistinct3(int *arr, int n){
    unordered_map<int,int> mpp;
    
    for(int i=0; i<n; i++){
        mpp[arr[i]]=1;
    }
    
    return mpp.size();
    //Time Complexity: O(N)
    //Space Complexity: O(N)(in worst case)
}

int main()
{
    int arr[5]={2,6,2,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int distele=CountDistinct3(arr,n);
    cout<<distele;

    return 0;
}