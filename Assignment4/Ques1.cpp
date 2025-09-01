/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/

#include <iostream>
#define Maxlen 5
using namespace std;
class Queue
{
  int Rear = -1;
  int front = -1;
  int Que[Maxlen];

public:
  bool isFull()
  {
    if (Rear == Maxlen - 1)
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
    if (Maxlen == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void enqueue(int x)
  {
    if (isFull())
    {
      cout << "Queue reached its Max Length" << endl;
    }
    else if (Rear == -1 && front == -1)
    {
      front = 0;
      Rear = 0;
      Que[Rear] = x;
      cout << x << " is inserted at:" << Rear << endl;
    }
    else
    {
      Rear++;
      Que[Rear] = x;
      cout << x << " is inserted at:" << Rear << endl;
    }
  }

  void dequeue()
  {
    int item;
    if (isEmpty())
    {
      cout << "Queue is Empty";
    }
    else if (front == 0 && Rear == 0)
    {
      item = Que[front];
      cout << "\n\nITEM DELETED: " << item << " from index " << front<<endl;
      front = -1;
      Rear = -1;
    }
    else
    {
      item = Que[front];
      cout << "\n\nITEM DELETED: " << item << " from index " << front<<endl;
      front++;
    }
  }

  void Display()
  {
    if (isEmpty())
    {
      cout << "\n\nQUEUE IS EMPTY\n";
    }
    else
    {
      for (int i = front; i <= Rear; i++)
      {
        cout << Que[i]<<" ";
      }
    }
    cout<<endl;
  }


  void Peek()
  {
    if(!isEmpty())
    {
      cout<<"Top Element is:"<<Que[front];
    }
    else
    {
      cout<<"Queue Is Empty";
    }
  }
};



int main()
{
  Queue q;

      q.Display();
      q.enqueue(10);
      q.enqueue(20);

      q.Display();
      q.dequeue();

      q.enqueue(30);
      q.enqueue(40);
      q.enqueue(50);
      q.enqueue(60);

      q.Display();
      q.Peek();
      return 0;
}