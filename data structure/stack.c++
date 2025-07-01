#include <iostream>
#include <stdio.h>
#define MAXSIZE 5 // to make size of the stack const
using namespace std;

class Stack
{
public:
  int data[MAXSIZE];
  int top;
  Stack()
  {
    top = -1;
  }
  void push(int value)
  {
    if (top == MAXSIZE - 1)
    {
      cout << " stack is full" << endl;
    }
    else
    {
      data[++top] = value;
    }
  }
  int pop()
  {
    if (top == -1)
    {
      cout << "stack is empty" << endl;
      return -1;
    }
    else
    {
      return data[top--];
    }
  }
  int topElement()
  {
    if (top == -1)
    {
      cout << "stack is empty" << endl;
    }
    else
    {
      return data[top];
    }
  }
  bool isFound(int value)
  {
    for (int i = top; i >= 0; i--)
    {
      if (data[i] == value)
        return true;
    }
    return false;
  }
  int size() {
    return top + 1;
}


  void display()
  {
    if (top == -1)
    {
      cout << "stack is empty" << endl;
    }
    else
    {
      for (int i = top; i >= 0; i--) // LIFO
      {
        cout << data[i] << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.display();
  cout << "\n";
  cout << "Top element is: " << s.topElement() << endl;
  cout << "\n";
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.display();
}
