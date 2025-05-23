#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
public:
  int arr[MAX], top;
  Stack() { top = -1; }
  void push(int x) { arr[++top] = x; }
  int pop() { return arr[top--]; }
  double average()
  {
    int sum = 0;
    for (int i = 0; i <= top; i++)
      sum += arr[i];
    return (double)sum / (top + 1);
  }
  void print()
  {
    for (int i = 0; i <= top; i++)
      cout << arr[i];
    cout << endl;
  }
};

int main()
{
  Stack s;
  s.push(0);
  s.push(1);
  s.push(5);
  s.push(2);
  s.push(4);
  s.push(7);
  cout << "Stack elements: ";
  s.print();
  cout << "Average: " << s.average() << endl;
  s.pop();
  s.pop();
  cout << "After removing two: ";
  s.print();
  s.push(10);
  s.push(-1);
  cout << "After adding two: ";
  s.print();
  cout << "Average: " << s.average() << endl;
  return 0;
}
