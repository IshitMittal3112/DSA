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

int Insert(int *arr, int pos, int num, int n)
{
    int i;
    for (i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = num;
    n = n + 1;
    return n;
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

int Linear_Search(int *arr, int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return (i + 1);
        }
    }
    return -1;
}
 int main()
{
     int arr[100], i, n, num, pos;
     char op;
     cout << "Enter the Number of Elements:";
     cin >> n;
     cout << "\n Enter the Elements:";
     for (i = 0; i < n; i++)
     {
         cin >> arr[i];
     }
     cout << "D is for Display\nI is For Insertion\nR is for Deletion\nL is for Linear Search";
     cout << "\n Enter the Operation u Want to Apply(D/I/R/L):";
     cin >> op;
     switch (op)
     {
     case 'D':

         Print_Array(arr, i, n);
         break;

     case 'I':

         cout << "Enter the Element u Want too Add";
         cin >> num;
         cout << "\n Enter the Position";
         cin >> pos;
         n = Insert(arr, pos, num, n);
         Print_Array(arr, i, n);
         break;

     case 'R':

         cout << "Enter the Position At which u want to delete Number:";
         cin >> pos;
         n = Delete(arr, pos, n);
         Print_Array(arr, i, n);
         break;

     case 'L':

         cout << "Enter the Elements u want to search:";
         cin >> num;
         pos = Linear_Search(arr, n, num);
         if (pos != -1)
         {
             cout << num << "is Found at Position:" << pos;
         }
         else
         {
             cout << "No Number Found";
         }
         break;
     default:

         cout << "Enter Valid Function";
         break;
     }
     return 0;
 }