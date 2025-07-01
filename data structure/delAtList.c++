#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int d = 0, Node *p = 0)
  {
    data = d;
    next = p;
  }
  ~Node() { cout << "NODES deleted \n"; }
};

class LinkedList
{
public:
  Node *head = NULL;
  bool isEmpty() { return head == NULL; }
  void insert(int newvalue)
  {
    Node *newNode = new Node(newvalue, head);
    head = newNode;
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
    for (int i = 0; prev && i < position - 1; i++)
      prev = prev->next;
    if (!prev || !prev->next)
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
      cout << "Empty list\n";
      return -1;
    }

    Node *p = head;

    for (int i = 0; p && i < position; i++)
      p = p->next;

    // لو مفيش نود بعدها نقدر نحذفها
    if (!p || !p->next)
    {
      cout << "No node exists after the given position.\n";
      return -1;
    }

    Node *toDelete = p->next;   // النود اللي هنحذفها
    int value = toDelete->data; // ناخد قيمتها
    p->next = toDelete->next;   // نربط النود اللي قبلها باللي بعدها

    delete toDelete;
    return value;
  }

  int DelBefore(int position)
  {
    // لو الليست فاضية أو المكان مش منطقي (أول عنصر مفيش قبله حاجة)
    if (isEmpty() || position <= 1)
    {
      cout << "Invalid position: No node exists before position " << position << endl;
      return -1;
    }

    // لو position = 2 → نحذف أول نود (head)
    if (position == 2)
    {
      Node *toDelete = head;
      int value = toDelete->data;
      head = head->next;
      delete toDelete;
      return value;
    }

    // نروح للنود اللي قبل النود اللي عايزين نحذفها
    Node *prev = head;
    for (int i = 0; prev && i < position - 3; i++)
      prev = prev->next;

    // لو خرجنا بره حدود الليست
    if (!prev || !prev->next)
    {
      cout << "Position out of bounds\n";
      return -1;
    }

    // نحذف النود اللي قبل position
    Node *toDelete = prev->next;
    int value = toDelete->data;
    prev->next = toDelete->next;
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
    for (int i = 0; p && i < position; i++)
      p = p->next;
    if (!p)
    {
      cout << "Position out of bounds\n";
      return;
    }
    p->data = newValue;
  }
  void printList()
  {
    Node *temp = head;
    while (temp)
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
  list.insert(10);
  list.insert(166);
  list.insert(50);
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
  list.DelBefore(3);
  cout << "After DelBefore(3): ";
  list.printList();
  cout << endl;
  list.UpdateAt(1, 99);
  cout << "After UpdateAt(1, 99): ";
  list.printList();
  cout << endl;
  return 0;
}
