#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool is_pair(char opening,char closing)
{
    if(opening=='(' && closing==')')
    {
        return true;
    }
    else if (opening=='[' && closing==']')
    {
        return true;
    }
    else if (opening=='{' && closing=='}')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_parentheses(string &exp)
{
    stack<char> ch;
    for (int i=0;i<exp.length();i++)
    {
        if (exp[i]== '(' || exp[i]=='{' || exp[i]=='[')
        {
            ch.push(exp[i]);
        }
       else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (ch.empty() || (!is_pair(ch.top(),exp[i])))
            {
                return false;
            }
            else
            {
                ch.pop();
            }
        }
    }
    ch.empty() ? true:false;
}

int main()
{
	string expr="{([}])";
	if(is_parentheses(expr))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}


//Time Complexity O(n)
//Space Complexity O(n)