/*#include <iostream>
#include <string>
using namespace std;
void Swap_Char(char &a,char &b)
{
    char temp=a;
    a=b;
    b=temp;
}
void Sort_String(string &ch,int n)
{
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (ch[j]>ch[j+1])
            {
                Swap_Char(ch[j],ch[j+1]);
            }
            else 
            {
                continue;
            } 
        }
    }
}
int main()
{
    string str="Hello";
    int n=str.length();
    Sort_String(str,n);
    cout<<str;
}*/



#include <iostream>
#include <string>
using namespace std;

void Swap_String(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void Sort_String(string *ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ch[j] > ch[j + 1])
            {
                Swap_String(ch[j], ch[j + 1]);
            }
        }
    }
}

int main()
{
    string str[] = {"Hello","Ishit","Mittal","Apple"};
    int n = sizeof(str)/sizeof(str[0]);
    Sort_String(str,n);
    for(int i=0;i<n;i++)
    {
        cout<<str[i]<<"\t";
    }
}