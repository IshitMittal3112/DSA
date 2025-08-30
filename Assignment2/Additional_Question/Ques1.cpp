/*Find two numbers in an array whose difference equals K. Given an array arr[] and a
positive integer k, the task is to count all pairs (i, j) such that i < j and absolute value of
(arr[i] - arr[j]) is equal to k.*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void count_Pairs(vector<int> &arr,int k)
{
  int i=0,j=0;
  int n=arr.size();
  sort(arr.begin(),arr.end());
  int count=0;
  /*for (i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(arr[j]-arr[i]==k)
      {
        count++;
      }
    }
  }
  cout<<count;*/

  while(j<n)
  {
    if (i==j)
    {
      j++;
      continue;
    }
    if(arr[j]-arr[i]<k)
    {
      j++;
    }
    else if(arr[j]-arr[i]>k)
    {
      i++;
      j=i+1;
    }
    else
    {
      int ele1 = arr[i], ele2 = arr[j];
            int cnt1 = 0, cnt2 = 0;
          
            // Count frequency of first element of the pair
            while(j < n && arr[j] == ele2) {
                j++;
                cnt2++;
            }
          
            // Count frequency of second element of the pair
            while(i < n && arr[i] == ele1) {
                i++;
                cnt1++;
            }
          
            // If both the elements are same, then count of
            // pairs = the number of ways to choose 2 
            // elements among cnt1 elements
            if(ele1 == ele2) 
            	count += (cnt1 * (cnt1 - 1))/2;
          
            // If the elements are different, then count of
            // pairs = product of the count of both elements
            else 
            	count += (cnt1 * cnt2);
    }
  }
  cout<<count;
}
int main()
{
  vector<int>arr={8,16,12,16,4,0};
  int k=4;
  count_Pairs(arr,k);
  return 0;
}