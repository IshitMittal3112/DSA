#include <iostream>
#include <string>
using namespace std;
bool is_Vovel(char ch)
{
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' )
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void Delete_vovel(string &ch)
{
    int n=ch.length();
    int i=0,j=0;
    while(i<n)
    {
        if(!is_Vovel(ch[i]))
        {
            ch[j++]=ch[i];
        }
        i++;
    }
    ch.resize(j);
}
int main()
{
    string ch="Hello World";
    Delete_vovel(ch);
    cout<<ch;
}