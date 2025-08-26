/*#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int check_Priority(char a)
{
    if(a=='^') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    return 0;
}
void printStack(stack<char> ot) {
    vector<char> temp;

    // Reverse the stack into a vector
    while (!ot.empty()) {
        temp.push_back(ot.top());
        ot.pop();
    }

    // Print in reverse to show original order
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i];
    }
    cout << endl;
}
void To_Postfix(string &exp)
{
    stack<char> in;
    stack<char> ot;
    for(int i=0;i<exp.length();i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                in.push(exp[i]);
            }
        else if(exp[i]=='+' || exp[i]=='-'  || exp[i]=='*'  || exp[i]=='/'  || exp[i]=='^' )
            {
                if (!in.empty() && check_Priority(exp[i]) <= check_Priority(in.top()))
            {
                ot.push(in.top());
                in.pop();
                in.push(exp[i]);
            }
            else if (!in.empty() && check_Priority(exp[i]) <= check_Priority(in.top()))
            {
                in.push(exp[i]);
            }
            }
        if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
            {
                if(exp[i]=='+' || exp[i]=='-'  || exp[i]=='*'  || exp[i]=='/'  || exp[i]=='^' )
                {
                    ot.push(in.top());
                }
                else if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                {
                    in.pop();
                }
            }
        
        else
        {
            ot.push(exp[i]);
        }
    }
    printStack(ot);
}
int main()
{
    string ch="A+B*C/D+(E-F)";
    To_Postfix(ch);
}




#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string Infix2Postfix(string &s){
    int n=s.length();
    int i=0;
    stack<char>st;
    string ans="";

    while(i<n){
        if((s[i]>= 'A' && s[i]<='Z') ||
           (s[i]>= 'a' && s[i]<='z') ||
           (s[i]>= '0' && s[i]<='9')){
            ans=ans+s[i];
           }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
        }
        else{
            while(!st.empty() && priority(s[i] <= priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
    //Time Complexity: O(N)+O(N)
    //Space Complexity: O(N)+O(N)
}

int main(){
    string Inf="A+B*C/D+(E-F)";
    string Pof=Infix2Postfix(Inf);
    cout<<Pof;
    return 0;
}