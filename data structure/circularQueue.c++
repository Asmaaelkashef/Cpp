#include <iostream>
using namespace std;
#define MAX 5

class Queue
{
public:
  int queue[MAX];
  int front;
  int rear;

  Queue()
  {
    front = -1;
    rear = -1;
  }

  bool isEmpty()
  {
    return (front == -1 && rear == -1);
  }

  void enqueue(int element)
  {
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
    {
      cout << "Queue Overflow\n";
      return; // without , code will continue
    }

    if (front == -1 && rear == -1)
    {
      front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0)
    {
      rear = 0;
    }
    else
    {
      rear++;
    }
    queue[rear] = element;
  }

  int dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue Underflow\n";
      return -1;
    }

    int data = queue[front];

    if (front == rear)
    {
      front = rear = -1;
    }
    else if (front == MAX - 1)
    {
      front = 0;
    }
    else
    {
      front++;
    }
    return data;
  }

  int size()
  {
    if (isEmpty())
      return 0;
    if (rear >= front)
      return rear - front + 1;
    else
      return MAX - front + rear + 1;
  }

  void PrintQueue(string msg)
  {
    cout << msg << "\n";

    if (isEmpty())
    {
      cout << "Queue is Empty\n";
      return;
    }

    if (front <= rear)
    {
      for (int i = front; i <= rear; i++)
      {
        cout << queue[i];
        if (i == front)
        {
          cout << " <-- front";
        }
        if (i == rear)
        {
          cout << " <-- rear";
        }
        cout << endl;
      }
    }
    else
    {
      // بنطبعها علي جزئين
      for (int i = front; i < MAX; i++)
      {
        cout << queue[i];
        if (i == front)
          cout << " <-- front";
        cout << endl;
      }
      for (int i = 0; i <= rear; i++)
      {
        cout << queue[i];
        if (i == rear)
          cout << " <-- rear";
        cout << endl;
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
  q.enqueue(8);
  q.enqueue(5);
  q.enqueue(9);
  q.PrintQueue("Queue after inserting 1, 2, 3, 8, 5:");
  q.dequeue();
  q.PrintQueue("Queue after deleting one element:");
  q.enqueue(4);
  q.enqueue(6);
  q.PrintQueue("Final Queue:");
}