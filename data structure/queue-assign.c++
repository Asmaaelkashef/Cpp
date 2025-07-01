#include <iostream>
using namespace std;
#define MAX 100
class Queue
{
public:
  int arr[MAX], front, rear;
  Queue() { front = rear = -1; }
  bool isEmpty() { return front == -1; }
  bool isFull() { return (rear + 1) % MAX == front; }
  void enqueue(int x)
  {
    if (isFull())
    {
      cout << "Queue Full\n";
      return;
    }
    if (isEmpty())
      front = rear = 0;
    else
      rear = (rear + 1) % MAX;
    arr[rear] = x;
  }
  int dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue Empty\n";
      return -1;
    }
    int x = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % MAX;
    return x;
  }
  int peek()
  {
    if (!isEmpty())
      return arr[front];
    else
      return -1;
  }
  void printQueue()
  {
    if (isEmpty())
    {
      cout << "Queue Empty\n";
      return;
    }
    int i = front;
    while (true)
    {
      cout << arr[i] << " ";
      if (i == rear)
        break;
      i = (i + 1) % MAX;
    }
    cout << endl;
  }
  // question 2
  void reverseQueue()
  {
    if (isEmpty())
      return;
    int temp[MAX], size = 0;
    int i = front;
    while (true)
    {
      temp[size++] = arr[i];
      if (i == rear)
        break;
      i = (i + 1) % MAX; // ده اللي بيخليها circular
    }
    front = rear = -1;
    for (int j = size - 1; j >= 0; j--)
      enqueue(temp[j]);
  }
  // question 3
  void removeElement(int val)
  {
    if (isEmpty())
      return;
    int temp[MAX], size = 0;
    int i = front;
    while (true)
    {
      if (arr[i] != val)
        temp[size++] = arr[i];
      if (i == rear)
        break;
      i = (i + 1) % MAX;
    }
    front = rear = -1;
    for (int j = 0; j < size; j++)
      enqueue(temp[j]);
  }
  // question 4
  double average()
  {
    if (isEmpty())
      return 0;
    int sum = 0, count = 0;
    int i = front;
    while (true)
    {
      sum += arr[i];
      count++;
      if (i == rear)
        break;
      i = (i + 1) % MAX;
    }
    return (double)sum / count;
  }
};
int main()
{
  Queue q;
  q.enqueue(0);
  q.enqueue(1);
  q.enqueue(5);
  q.enqueue(2);
  q.enqueue(4);
  q.enqueue(7);
  cout << "Queue elements: ";
  q.printQueue();
  cout << "Front element: " << q.peek() << endl;
  cout << "Is queue empty? " << q.isEmpty() << endl;
  cout << "Is queue full? " << q.isFull() << endl;
  cout << "Average: " << q.average() << endl;
  cout << "Dequeue one element: " << q.dequeue() << endl;
  q.printQueue();
  cout << "Reverse the queue:\n";
  q.reverseQueue();
  q.printQueue();
  cout << "Remove element 2 from queue:\n";
  q.removeElement(2);
  q.printQueue();
  cout << "Average after removal: " << q.average() << endl;
  return 0;
}
