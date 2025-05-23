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
  }
};

class Circularlist
{
public:
  Node *head;
  Circularlist()
  {
    head = NULL;
  }
  bool isEmpty()
  {
    return (head == NULL);
  }
  void addToHead(int item)
  {
    Node *node = new Node;
    node->data = item;
    node->next = head;
    if (head == NULL) // list is empty
    {
      head = node;
      head->next = head; // circular list كدا الليست مفيهاش غير النود دي ف هي الاخيرة وبتشاور علي النود الاولي اللي هي برده
    }
    else
    {
      Node *q = head; // بوينتر للهيد بخليه يعدي ع كل النود لحد ميوصل للاخيرة
      while (q->next != head)
      {
        q = q->next;
      } //  لحد موصل للاخيرة اعدي ع كل النود
      q->next = node; // لما وصلت للاخيرة خليتها تشاور ع الهيد اللي هي النود الجديدة بتاعتي circular
      head = node;
    }
  }
  void addToTail(int item)
  {
    Node *node = new Node;
    node->data = item;
    node->next = head;
    if (head == NULL) // list is empty
    {
      head = node;
      head->next = head; // circular list
    }
    else
    {
      Node *q = head;
      while (q->next != head)
      {
        q = q->next;
      }
      q->next = node;
    }
  }
  void printList()
  {
    Node *node = head;
    while (node->next != head)
    {
      cout << node->data << " ";
      node = node->next;
    };
    cout << node->data << " ";
  }
  int countList()
  {
    int counter = 0;
    Node *node = head;
    do
    {
      counter++;
      node = node->next;
    } while (node != head); // بدل معمل do while اخلي الكاونتر بواحد اول مرة
    return counter;
  }
  int deleteFromHead()
  {
    int x;
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      exit(0);
    }
    else if (head->next == head) // if list contain only one node
    {
      x = head->data;
      delete head;
      head = NULL; // list becomes empty now
      return x;
    }
    else // case3: list contains more than one node
    {
      Node *p = head, *q = head; // p is pointer to the node we will delete
      while (q->next != head)
      {
        q = q->next;
      };
      head = head->next; // بنحدث الهيد عشان تشير للنود الي بعدها علشان الاولي هنمسحها
      q->next = head;    // حطيت لاخر نود الهيد الجديدة الصحيحة
      x = p->data;       // save data in variable before delete
      delete p;
      return x;
    }
  }
  int deleteFromTail()
  {
    int x;
    if (head == NULL) // list is empty
    {
      cout << "List is empty" << endl;
      exit(0);
    }
    else if (head->next == head) // if list contain only one node
    {
      x = head->data;
      delete head;
      head = NULL; // list becomes empty now
      return x;
    }
    else
    {
      Node *p = head, *q;
      while (p->next != head)
      {
        q = p;
        p = p->next;
      }
      x = p->data;
      delete p;
      q->next = head;
    }
  }
};

int main()
{
  Circularlist list;

  list.addToHead(5);
  list.addToTail(6);
  list.addToTail(7);
  list.addToTail(8);
  list.addToTail(9);
  cout << "\nnumber of Nodes in list : " << list.countList() << "  -->  ";
  list.printList();

  list.addToTail(10);
  list.addToTail(11);
  list.addToTail(12);
  cout << "\nnumber of Nodes in list : " << list.countList() << "  -->  ";
  list.printList();

  list.deleteFromHead();
  list.deleteFromHead();
  cout << "\nnumber of Nodes in list : " << list.countList() << "  -->  ";
  list.printList();

  return 0;
}