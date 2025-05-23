#include <iostream>
using namespace std;
#define MAX 100

class Stack {
public:
  int arr[MAX], top;
  Stack() { top = -1; }
  bool isEmpty() { return top == -1; }
  void push(int x) {
    if (top < MAX-1) arr[++top] = x;
  }
  int pop() {
    if (isEmpty()) { cout << "Stack Empty\n"; return -1; }
    return arr[top--];
  }
  int Top() {
    if (!isEmpty()) return arr[top];
    else return -1;
  }
  void print() {
    for (int i = top; i >= 0; i--) cout << arr[i];
    cout << endl;
  }
};

int main() {
  Stack s;
  cout << "Is stack empty? " << s.isEmpty() << endl;
  s.push(4); s.push(5); s.push(6); s.push(7);
  cout << "Stack elements: "; s.print();
  cout << "Remove an element: " << s.pop() << endl;
  cout << "Stack elements: "; s.print();
  cout << "Top element: " << s.Top() << endl;
  return 0;
}
