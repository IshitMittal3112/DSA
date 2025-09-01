
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string &s)
{
  stack<int> st;

  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];

    if (isdigit(c))
    {
      st.push(c - '0'); // convert char to int
    }
    else
    {
      // Operator → pop two values
      int num1 = st.top();
      st.pop();
      int num2 = st.top();
      st.pop();

      switch (c)
      {
      case '+':
        st.push(num1 + num2);
        break;
      case '-':
        st.push(num1 - num2);
        break;
      case '*':
        st.push(num1 * num2);
        break;
      case '/':
        st.push(num1 / num2);
        break;
      case '^':
        st.push(pow(num1, num2));
        break;
      }
    }
  }
  return st.top();
  // Time Complexity: O(N)
  // Space Complexity: O(N)
}

int main()
{
  string postfix = "23+5*3+";
  cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
  return 0;
}