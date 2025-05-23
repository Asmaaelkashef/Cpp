#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next, *prev;
  Node() { next = prev = 0; }
  Node(int d)
  {
    data = d;
    next = prev = 0;
  }
};
class Doubly_List
{
public:
  Node *head;
  Doubly_List() { head = NULL; }
  ~Doubly_List()
  {
    Node *p;
    while (head != NULL)
    {
      p = head;
      head = head->next;
      delete p;
    }
  }
  bool isEmpty() { return head == NULL; }
  void addToHead(int item)
  {
    Node *p = new Node;
    p->data = item;
    p->prev = NULL;
    if (head == NULL)
    {
      head = p;
      p->next = NULL;
    }
    else
    {
      head->prev = p;
      p->next = head;
      head = p;
    }
  }
  void addToTail(int item)
  {
    Node *p = new Node(item);
    p->next = NULL;
    if (head == NULL)
    {
      head = p;
      p->prev = NULL;
      return;
    }
    Node *q = head;
    while (q->next != NULL)
    {
      q = q->next;
    }
    q->next = p;
    p->prev = q;
  }
  string findNode(int item)
  {
    Node *p = head;
    int pos = 0;
    while (p != NULL)
    {
      if (p->data == item)
      {
        cout << "we find it in position :" << pos << endl;
        return "found";
      }
      p = p->next;
      pos++;
    }
    return "not found";
  }

  int deleteFromHead()
  {
    int x;
    if (head == NULL)
    {
      cout << "List Empty";
      exit(0);
    }
    else if (head->next == NULL)
    {
      x = head->data;
      delete head;
      head = NULL;
      return x;
    }
    else
    {
      Node *p = head;
      p->next->prev = NULL;
      head = head->next;
      x = p->data;
      delete p;
      return x;
    }
  }

  int deleteFromTail()
  {
    if (head == NULL)
    {
      cout << "List Empty";
      exit(0);
    }
    Node *p = head, *q = NULL;
    if (head->next == NULL)
    {
      int x = p->data;
      delete p;
      head = NULL;
      return x;
    }
    while (p->next != NULL)
    {
      q = p;
      p = p->next;
    }
    int x = p->data;
    q->next = NULL;
    delete p;
    return x;
  }

  void deleteNode(int item)
  {
    if (head == NULL)
    {
      cout << "List Empty";
      return;
    }
    if (head->data == item)
    {
      deleteFromHead();
      return;
    }
    Node *p = head->next;
    while (p != NULL) // طول محنا جوا الليست
    {
      if (p->data == item) // لو لاقينا اللي عايزين نحذفه
      {
        p->prev->next = p->next; // هخلي اللي قبل النود يشاور عالي بعد النود
        if (p->next != NULL)
        {
          p->next->prev = p->prev;
        }
        delete p;
        return;
      }
      p = p->next; // لو ملاقيناهوش ف نعدي عاللي بعده
    }
  }
  void printList()
  {
    Node *p = head;
    while (p != NULL)
    {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
};
int main()
{
  Doubly_List l;
  l.addToHead(5);
  l.addToTail(8);
  l.addToTail(9);
  cout << "List: ";
  l.printList();
  l.addToTail(4);
  l.addToTail(7);
  cout << "\nList: ";
  l.printList();
  l.deleteFromHead();
  cout << "\nList: ";
  l.printList();
  l.deleteFromTail();
  cout << "List: ";
  l.printList();
  cout << "\nFind 5 at position: " << l.findNode(5) << endl;
  l.deleteNode(5);
  cout << "\nList: ";
  l.printList();
  return 0;
}
