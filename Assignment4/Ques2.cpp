#include <iostream>
#define MAXLEN 5

using namespace std;

class Queue {
   private:
  int items[MAXLEN], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull() {
      if(front==rear+1 || front==0 && rear==MAXLEN-1)
        return true;
      else
        return false;

  }
  
  bool isEmpty() {
    if(front==-1)
        return true;
    else
        return false;
  }

  
  void enqueue(int element) {
      if(isFull())
        cout<<"Overflow"<<endl;
      else
      {
        if(front==-1 && rear==-1)
        {
          front=0;
          rear=0;
        }
        else
            rear=(rear+1)%MAXLEN;
        items[rear]=element;
      }

  }
  
  int dequeue() {
      int n;
    if(isEmpty())
        cout<<"Underflow"<<endl;
      else
      {
        n=items[front];
        if(front==rear)
        {
          front=-1;
          rear=-1;
        }
        else
            front=(front+1)%MAXLEN;
        return n;
      }
  }

  void display() {
    int i;
    if (isEmpty())
        cout << "\nQUEUE IS EMPTY\n" << endl;
    else {
      cout << endl<< "Items = ";
      for (i = front; i != rear; i = (i + 1) % MAXLEN)
        cout << items[i]<<" ";
      cout <<items[i];
    }
  }

    void Peek()
    {
        if(!isEmpty())
    {
      cout<<"Top Element is:"<<items[front];
    }
    else
    {
      cout<<"Queue Is Empty";
    }
    }
};

int main() {
  Queue q;
  q.dequeue();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.display();

  int elem = q.dequeue();

  if (elem != -1)
    cout <<"\nELEMENT DELETED: " << elem<<" FROM INDEX "<<endl;

  q.display();
  q.enqueue(7);
  q.display();
  q.enqueue(8);
  q.Peek();
  return 0;
}