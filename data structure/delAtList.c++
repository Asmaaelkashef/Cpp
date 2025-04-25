#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    next = 0;
  }
  Node(int d)
  {
    data = d;
    next = 0;
  }
  Node(int d, Node *p)
  {
    data = d;
    next = p;
  }
  ~Node()
  {
    cout << "NODES deleted \n";
  }
};

class LinkedList
{
public:
  Node *head;
  bool isEmpty()
  {
    return (head == NULL);
  }
  void insert(int newvalue)
  {
    Node *newNode = new Node();
    newNode->data = newvalue;
    if (isEmpty())
    {
      newNode->next = NULL;
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }
  int DelAt(int position)
  {
    if (isEmpty())
    {
      cout << "empty list\n";
      return 0;
    }
    if (position == 0)
    {
      Node *p = head;
      head = head->next;
      int value = p->data;
      delete p;
      return value;
    }
    Node *prev = head;
    for (int i = 0; prev != NULL && i < position - 1; i++)
    {
      prev = prev->next;
    }
    if (prev == NULL || prev->next == NULL)
    {
      cout << "Position out of bounds\n";
      return -1;
    }
    Node *p = prev->next;
    prev->next = p->next;
    int value = p->data;
    delete p;
    return value;
  }
  int DelAfter(int position)
  {
    if (isEmpty())
    {
      cout << "empty list\n";
      return -1;
    }
    Node *p = head;
    for (int i = 0; p != NULL && i < position; i++)
    {
      p = p->next;
    }
    if (p == NULL || p->next == NULL)
    {
      cout << "No node exists after the given position.\n";
      return 0;
    }
    Node *toDelete = p->next;
    p->next = toDelete->next;
    int value = toDelete->data;
    delete toDelete;
    return value;
  }
  int DelBefore(int position)
  {
    if (isEmpty() || position <= 0)
    {
      cout << "Invalid position\n";
      return 0;
    }
    if (position == 1)
    {
      Node *p = head;
      head = head->next;
      int value = p->data;
      delete p;
      return value;
    }
    Node *prev = head;
    for (int i = 0; prev != NULL && i < position - 2; i++)
    {
      prev = prev->next;
    }
    if (prev == NULL || prev->next == NULL)
    {
      cout << "Position out of bounds\n";
      return -1;
    }
    Node *toDelete = prev->next;
    prev->next = toDelete->next;
    int value = toDelete->data;
    delete toDelete;
    return value;
  }
  void UpdateAt(int position, int newValue)
  {
    if (isEmpty())
    {
      cout << "empty list\n";
      return;
    }
    Node *p = head;
    for (int i = 0; p != NULL && i < position; i++)
    {
      p = p->next;
    }
    if (p == NULL)
    {
      cout << "Position out of bounds\n";
      return;
    }
    p->data = newValue;
  }
  void printList()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
};
int main()
{
  LinkedList list;
  list.insert(10);
  list.insert(20);
  list.insert(30);
  list.insert(40);
  list.insert(50);
  cout << "Initial list: ";
  list.printList();
  cout << endl;
  list.DelAt(2);
  cout << "After DelAt(2): ";
  list.printList();
  cout << endl;
  list.DelAfter(1);
  cout << "After DelAfter(1): ";
  list.printList();
  cout << endl;
  list.DelBefore(1);
  cout << "After DelBefore(1): ";
  list.printList();
  cout << endl;
  list.UpdateAt(1, 99);
  cout << "After UpdateAt(1, 99): ";
  list.printList();
  cout << endl;
  return 0;
}
