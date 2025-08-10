#include <iostream>
using namespace std;
int Print_Array(int *arr, int i, int n)
{
    cout << "Array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i];
        cout << "\t";
    }
}
int Delete(int *arr, int pos, int n)
{
    int i;
    for (i = pos - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
    return n;
}
int Delete_Duplicate(int *arr, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
            //    for (k = j; k < n - 1; k++)
            //    {
            //        arr[k] = arr[k + 1];
            //    }
            //    n--;
           n= Delete(arr,i,n);
            }
            else
            {
                j++;
            }
        }
    }
    return n;
}
 int main()
{
     int arr[100], i, n ;
     char op;
     cout << "Enter the Number of Elements:";
     cin >> n;
     cout << "\n Enter the Elements:";
     for (i = 0; i < n; i++)
     {
         cin >> arr[i];
     }
     Print_Array(arr, i, n);
     n = Delete_Duplicate(arr, n);
     cout << "Array Without Duplicate Elements:\n";
     Print_Array(arr, i, n);
     return 0;
 }