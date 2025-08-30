#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sort_Array(vector<int> &arr,int n)
{
  int low=0;
  int mid=0;
  int high=n-1;
  while (mid<=high)
  {
    if(arr[mid]==0)
    {
      swap(arr[low++],arr[mid++]);
    }
    else if(arr[mid]==1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid],arr[high--]);
    }
  }
}
int main()
{
  vector<int>arr={0,1,2,0,1,2};
  int n=arr.size();
  //sort(arr.begin(),arr.end());
  sort_Array(arr,n);
  for (int i=0;i<n;i++)
  {
    cout<<arr[i]<<"\t";
  }

}