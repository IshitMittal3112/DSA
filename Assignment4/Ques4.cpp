 #include <iostream>
#include <queue>
#include <string>
using namespace std;
string Conversion(string &ch)
{
  queue<char> qu;
  int n=ch.length();
  int i;
  string st= "";
  for(char c : ch)
  {
    if(qu.empty())
    {
      qu.push(c);
      st+=c;
    }
    else if(c==qu.front())
    {
      qu.pop();
      st+="-1";
    }
    else
    {
      st+=qu.front();
    }
  }
  return st;
}
int main()
{
  string ch = "aabc";
  ch=Conversion(ch);
  cout<<ch;
}