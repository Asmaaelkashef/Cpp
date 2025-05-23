#include <iostream>
using namespace std;
#define maxsize 10

class Queue
{
public:
  int front;
  int rear;
  int queue[maxsize];

  Queue()
  {
    front = -1;
    rear = -1;
  }

  bool isEmpty()
  {
    return front == -1 && rear == -1;
  }

  void enqueue(int element)
  {
    if (rear != maxsize - 1)
    {
      if (isEmpty())
      {
        front = 0;
        queue[++rear] = element;
      }
      else
      {
        queue[++rear] = element;
      }
    }
    else
    {
      cout << "Queue is full.\n";
    }
  }

  int dequeue()
  {
    if (!isEmpty() && front <= rear)
    {
      int element = queue[front];
      if (front == rear)
      {
        front = -1;
        rear = -1;
      }
      else
      {
        front++;
      }
      return element;
    }
    else
    {
      cout << "Queue is empty!\n";
      return -1; // إشارة إلى أن الطابور فارغ
    }
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "Queue is empty!\n";
      return -1;
    }
    else
    {
      return queue[front];
    }
  }

  void display(string msg)
  {
    cout << msg << "\n";
    if (isEmpty())
    {
      cout << "Queue is empty!\n";
    }
    else
    {
      for (int i = front; i <= rear; i++)
      {
        if (i == front && i == rear)
          cout << queue[i] << " <-- front & rear\n";
        else if (i == front)
          cout << queue[i] << " <-- front\n";
        else if (i == rear)
          cout << queue[i] << " <-- rear\n";
        else
          cout << queue[i] << endl;
      }
    }
  }
};

int main()
{
  Queue queue;
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);
  queue.enqueue(40);
  queue.display("Queue after inserting 10, 20, 30, and 40:");

  queue.enqueue(50);
  queue.display("Queue after inserting 50:");

  int element = queue.peek();
  cout << "Peek element returned: " << element << endl;

  element = queue.dequeue();
  cout << "Dequeue element returned: " << element << endl;

  element = queue.dequeue();
  cout << "Dequeue element returned: " << element << endl;

  queue.display("Queue after removing two elements:");

  return 0;
}
