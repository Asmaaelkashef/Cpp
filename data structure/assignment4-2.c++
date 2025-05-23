#include <iostream>
using namespace std;
#define MAX 5

class Stack {
public:
  int arr[MAX], top;
  Stack() { top = -1; }
  bool isFull() { return top == MAX-1; }
  void push(int x) {
    if (!isFull()) arr[++top] = x;
  }
  void print() {
    for (int i = 0; i <= top; i++) cout << arr[i];
    cout << endl;
  }
};

int main() {
  Stack s;
  s.push(1); s.push(2); s.push(5); s.push(6); s.push(9);
  cout << "Stack elements: "; s.print();
  cout << "Is the stack full? " << s.isFull() << endl;
  return 0;
}
