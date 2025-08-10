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
void reverse_array(int *arr, int n)
{
    int i, s;
    int b[100];
    for (i = n-1;i>=0;i--)
    {
        b[n-(i+1)]=arr[i];
    }
    Print_Array(b,i,n);
}
int main()
{
    int arr[100], i, n;
    char op;
    cout << "Enter the Number of Elements:";
    cin >> n;
    cout << "\n Enter the Elements:";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse_array(arr, n);
}