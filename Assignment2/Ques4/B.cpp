#include <iostream>
#include <string>
using namespace std;
void Swap_Char(char &a,char &b)
{
    char temp=a;
    a=b;
    b=temp;
}
void Reverse_Str(string &str1)
{
    int n=str1.length();
    int i;
    for (i=0;i<n/2;i++)
    {
        Swap_Char(str1[i],str1[n-i-1]);
    }
}
int main()
{
    string str1="Hello";
    Reverse_Str(str1);
    cout<<"Reversed String:"<<str1<<endl;
}