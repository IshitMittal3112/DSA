#include <iostream>
#include <vector>
using namespace std;

int NoOfInversions(int *arr, int n){
    int cnt=0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){
                cnt++;
            }
        }
    }
    return cnt;
    // Time Complexity: O(N^2)
    //Space Complexity: O(1)
}
//Otimized Merge code for Counting Inversions Using Merge Sort.


int Merge(int *arr, int low, int mid, int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
            right++;
        }
        
    }
    
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}

int NoOfInversionsUsingMergeSort(int *arr,int low, int high){
    int cnt=0;
    if(low>=high){
        return cnt;
    }
    
    int mid= (low+high)/2;
    cnt += NoOfInversionsUsingMergeSort(arr,low,mid);
    cnt += NoOfInversionsUsingMergeSort(arr,mid+1,high);
    cnt += Merge(arr,low,mid,high);
    
    
    return cnt;
    // Time Complexity: O(N*log(N))
    //Space Complexity: O(N)
}



int main()
{
   int A[7]={1,3,2,5,7,6,4};
   int n=sizeof(A)/sizeof(A[0]);
   int num=NoOfInversionsUsingMergeSort(A,0,n-1);
   cout<<num;

    return 0;
}