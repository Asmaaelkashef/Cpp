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
  LinkedList()
  {
    head = NULL;
  }
  bool isEmpty()
  {
    return (head == NULL);
  }
  void insertFirst(int newvalue)
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
  void insertLast(int newvalue)
  {
    Node *newNode = new Node;
    newNode->data = newvalue;
    Node *q = head;
    while (q->next != NULL)
    {
      q = q->next;
    }
    q->next = newNode;
    newNode->next = NULL;
  }
  bool isFound(int key)
  {
    bool found = false;
    Node *temp = head;
    while (temp != NULL)
    {
      if (temp->data == key)
        found = true;
      else
        temp = temp->next;
    }
    return false;
  }
  int deleteFromHead()
  {
    int x;
    if (isEmpty())
    {
      cout << "list Empty";
    }
    else if (head->next == NULL)
    {
      x = head->data;
      delete head;
      return x;
    }
    else
    {
      Node *p = head;
      head = head->next;
      x = p->data;
      delete p;
      return x;
    }
  }
  int deleteFromTail()
  {
    int x;
    if (head == NULL)
    {
      cout << "list Empty";
    }
    else if (head->next == NULL)
    {
      x = head->data;
      delete head;
      return x;
    }
    else
    {
      Node *p = head, *q;
      while (p->next != NULL)
      {
        q = p;
        p = p->next;
      }
      x = p->data;
      delete p;
      q->next = 0;
      return x;
    }
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
  int countList()
  {
    int countList = 0; // initialize countList
    Node *temp = head; // عملت نود احتياطي بديل عن الهيد
    while (temp != NULL)
    {
      countList++;
      temp = temp->next; // عشان اخلي النود ينتقل للي بعده
    }
    return countList;
  }
  ~LinkedList()
  {
    Node *p = head, *q;
    while (p != NULL)
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
  cout << " after insert , list contains " << list.countList();

  cout << "\n enter item to search in the list : \n";
  int item;
  cin >> item;
  if (list.isFound(item))
    cout << "item found in the list ";
  else
    cout << "item not found in the list ";

  list.deleteFromHead();
  list.deleteFromTail();
  return 0;
}