#include <iostream>
#include <string>
using namespace std;
void concatenate(string &str1,string &str2)
{
    str1=str1+" "+str2;
}
int main()
{
    string str1="Hello";
    string str2="World";
    concatenate(str1,str2);
    cout<<str1;
    return 0;
}