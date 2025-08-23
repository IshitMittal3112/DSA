/*1. Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().*/

#include <iostream>
using namespace std;
class stack
{
    int element[5];
    int top=-1;
    public:
    

    bool isFull()
    {
        if(top==4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



    void push(int x)
    {
        if (!isFull())
        {
            top++;
            element[top]=x;
        }
        else 
        {
            cout<<"Stack Overloaded";
        }
    }



    void pop()
    {
        if(isEmpty())
        {
            cout<<"Function is Empty";
        }
        else
        {
            top--;
        }
    }



    void display()
    {
        for(int i=top;i>-1;i--)
        {
            cout<<element[i];
        }
    }



    void peek()
    {
        if(!isEmpty())
        {
            cout<<element[top];
        }
        else
        {
            cout<<"Stack Empty";
        }
    }
};




int main()
{
    stack S;
    for (int i=0;i<=4;i++)
        S.push(10+i);
    S.display();
    S.pop();
    cout<<"\n";
    S.display();
    cout<<"\n";
    S.push(50);
    S.display();
    cout<<"\n";
    S.push(20);
    cout<<"\n";
    S.display();
    cout<<"\n";
    cout<<"Top element is: ";
    S.peek();
}