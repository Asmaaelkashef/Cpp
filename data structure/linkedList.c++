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
  Node *head;
  LinkedList() { head = NULL; }
  bool isEmpty() { return head == NULL; }
  void insertFirst(int newvalue)
  {
    Node *newNode = new Node(newvalue, head);
    head = newNode;
  }
  void insertLast(int newvalue)
  {
    Node *newNode = new Node(newvalue);
    if (isEmpty())
      head = newNode;
    else
    {
      Node *q = head;
      while (q->next)
        q = q->next;
      q->next = newNode;
    }
  }
  bool isFound(int key)
  {
    Node *temp = head;
    while (temp)
    {
      if (temp->data == key)
        return true;
      temp = temp->next;
    }
    return false;
  }
  int deleteFromHead()
  {
    if (isEmpty())
    {
      cout << "list Empty";
      return -1;
    }
    Node *p = head;
    int x = p->data;
    head = head->next;
    delete p;
    return x;
  }
  int deleteFromTail()
  {
    if (isEmpty())
    {
      cout << "list Empty";
      return -1;
    }
    if (!head->next)
    {
      int x = head->data;
      delete head;
      head = NULL;
      return x;
    }
    Node *p = head, *q = NULL;
    while (p->next)
    {
      q = p;
      p = p->next;
    }
    int x = p->data;
    delete p;
    q->next = NULL;
    return x;
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
  int countList()
  {
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
      cnt++;
      temp = temp->next;
    }
    return cnt;
  }
  int getMinimum()
  {
    if (isEmpty())
      return -1;
    int minVal = head->data;
    Node *temp = head->next;
    while (temp)
    {
      if (temp->data < minVal)
        minVal = temp->data;
      temp = temp->next;
    }
    return minVal;
  }
  int sumOdd()
  {
    int sum = 0;
    Node *temp = head;
    while (temp)
    {
      if (temp->data % 2)
        sum += temp->data;
      temp = temp->next;
    }
    return sum;
  }
  LinkedList copyList()
  {
    LinkedList newList;
    Node *temp = head;
    while (temp)
    {
      newList.insertLast(temp->data);
      temp = temp->next;
    }
    return newList;
  }
  ~LinkedList()
  {
    Node *p = head, *q;
    while (p)
    {
      q = p->next;
      delete p;
      p = q;
    }
  }
};

int main()
{
  LinkedList list;
  if (list.isEmpty())
    cout << " list is empty ";
  else
    cout << " list contains " << list.countList();
  cout << "\n--------------------------------\n";
  for (int i = 0; i < 4; i++)
  {
    cout << "enter item to insert in the list : \n";
    int item;
    cin >> item;
    list.insertFirst(item);
  }
  cout << "After inserting items in the list : \n";
  list.printList();
  cout << "\n after insert , list contains " << list.countList();
  cout << "\n enter item to search in the list : \n";
  int item;
  cin >> item;
  if (list.isFound(item))
    cout << "item found in the list ";
  else
    cout << "item not found in the list ";
  cout << "\n minimum item in the list : " << list.getMinimum();
  cout << "\n sum of odd items in the list : " << list.sumOdd();
  LinkedList copiedList = list.copyList();
  cout << "\n copied list is : ";
  copiedList.printList();
  list.deleteFromHead();
  list.deleteFromTail();
  return 0;
}
