#include <iostream>
#include <queue>
using namespace std;
void Rearrange(queue<int> &q)
{
  queue<int> tq;
  int i;
  int n=q.size();
  for(i=0;i<n/2;i++)
  {
    tq.push(q.front());
    q.pop();
  }
  for(i=0;i<n/2;i++)
  {
    q.push(tq.front());
    tq.pop();
    q.push(q.front());
    q.pop();
  }
}
int main()
{
  queue<int> q;
  q.push(4);
  q.push(7);
  q.push(11);
  q.push(20);
  q.push(5);
  q.push(9);
  Rearrange(q);
  while(!q.empty())
  {
    cout<<q.front()<<"\t";
    q.pop();
  }
}