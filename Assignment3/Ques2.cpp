#include <iostream>
#include <string>
#include <stack>
using namespace std;
void Reversed_String(string &ch)
{
    int n=ch.length();
    stack<char> c;
    for (int i=0;i<n;i++)
    {
        c.push(ch[i]);
    }
    string Reversed;
    while(!c.empty())
    {
        Reversed+=c.top();
        c.pop();
    }
    cout<<Reversed;
}
int main()
{
    string ch="DataStructure";
    Reversed_String(ch);
}