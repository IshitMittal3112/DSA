#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void Display2D(int (&arr)[3][3],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void Transpose(int (&arr1)[3][3],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            //swap(arr1[i][j],arr1[j][i]);
            cout<<arr1[j][i]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int arr1[3][3]={
        {1,2,3},{4,5,6},{7,8,9}};
        Display2D(arr1,3);
    Transpose(arr1,3);
    

}