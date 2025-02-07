#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 3

class Queue
{
public:
  int data[MAX];
  int front;
  int rear;

  Queue()
  {
    front = -1;
    rear = -1;
  }
  int isEmpty()
  {
    if (front = rear == -1)
      return 1;
    return 0;
  }
  void enqueue(int element)
  {
    if (front == 0 && rear == MAX - 1)
      cout << "Queue Overflow";
    else if (front == -1 && rear == -1) // queue is empty
    {
      front = rear = 0;
      data[rear] = element;
    }
    else if (rear == MAX - 1)
    {
      rear = 0;
      data[rear] = element;
    }
    else
    {
      rear++;
      data[rear] = element;
    }
  }
  int dequeue()
  {
    int x;
    if (front == -1 && rear == -1)
      cout << "Queue Underflow";
    else
    {
      x = data[front];
      if (front == rear) // only one element in queue
        front = rear = -1;
      else if (front == MAX - 1)
        front = 0;
      else
        front++;
      return x;
    }
  }
  void PrintQueue()
		{
			int f = front, r = rear;
			if(front == -1 && rear == -1 )
				cout << "Queue is Empty";
			else if(front == rear)
				cout << "\t" << data[front];
			else if (f <= r)
				{
					while(f<=r)
					{
						cout << "\t" << data[f];
						f++;
					}
				}
			else
			{
				while(f <= MAX-1)
					{
						cout << "\t" << data[f];
						f++;
					}
					f=0;
					while(f<=r)
					{
						cout << "\t" << data[f] ;
						f++;
					}
				
			}	
			cout << "\n";
		}		
};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.PrintQueue();
	q.dequeue();
	q.enqueue(4);
	q.enqueue(6);
	q.PrintQueue();
}

