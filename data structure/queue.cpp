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
  void enqueue(int element)
  {
    if (rear != maxsize - 1)
    {
      if (front == -1 && rear == -1) // queue is empty
      {
        front++;                 // to set front & rear to point
        queue[++rear] = element; // insert from end
      }
      else
      {
        queue[++rear] = element;
      }
    }
    else
    {
      cout << "queue is full . \n";
    }
  }
  int dequeue()
  {
    if (front != -1 && rear != -1 && front <= rear)
    {
      int element = queue[front]; // dequeue from the start
      if (front == rear)          // check if last element
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
      cout << "queue is empty ! \n ";
    }
  }
  int peek()
  {
    if (front == -1 && rear == -1)
    {
      cout << " queue is empty ! \n";
    }
    else
    {
      return queue[front];
    }
  }
  void display(string msg)
  {
    cout << msg << "\n";
    if (front == -1 && rear == -1)
    {
      cout << " queue is empty ! \n";
    }
    cout << queue[front] << " <-- front" << endl;
    for (int i = front + 1; i < rear; i++)
    {
      cout << queue[i] << endl;
    }
    cout << queue[rear] << " <-- rear" << endl;
  }
};

int main()
{
  Queue queue;
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);
  queue.enqueue(40);
  queue.display("Queue after inserting 10 20 30 and 40");
  queue.enqueue(50);
  queue.display("Queue after inserting 50");
  int element = queue.peek();
  cout << "Peek element returned " << element << endl;
  element = queue.dequeue();
  cout << "Dequeue element returned " << element << endl;
  element = queue.dequeue();
  cout << "Dequeue element returned " << element << endl;
  queue.display("Queue after removing two elements");
}