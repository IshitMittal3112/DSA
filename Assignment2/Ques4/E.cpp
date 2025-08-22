#include <iostream>
#include <string>
using namespace std;
void U_to_L(string &ch)
{
    int n=ch.length();
    for(int i=0;i<n;i++)
    {
        if(isupper(ch[i]))
        {
            ch[i]=ch[i]+('a'-'A');
        }
        else 
        {
            continue;
        }
    }
}
int main()
{
    string str="HELLO";
    U_to_L(str);
    cout<<str;
}