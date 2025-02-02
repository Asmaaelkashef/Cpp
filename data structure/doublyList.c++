#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *prev;
  Node()
  {
    next = prev = 0;
  }
  Node(int d)
  {
    data = d;
    next = prev = 0;
  }
  Node(int d, Node *p, Node *q)
  {
    data = d;
    next = p;
    prev = q;
  }
};

class DoublyLinkedList
{
public:
  Node *head;
  DoublyLinkedList()
  {
    head = NULL;
  }
  void addToHead(int item)
  {
    Node *p = new Node;
    p->data = item;
    p->prev = NULL; // fisrt Node always have prev point to null

    if (head != NULL) // list have Nodes
    {
      head->prev = p;
    }
    p->next = head;
    head = p; // modify head
  }
  void addToTail(int item)
  {
    Node *p = new Node;
    p->data = item;
    p->next = NULL; // because its the last node in list

    if (head != NULL) // list is not empty
    {
      Node *q = head;
      while (q->next != NULL) // عشان اخلي الاخيرة تبقي قبل الاخيرة
        q = q->next;
      q->next = p;
      p->prev = q;
    }
    else
    {
      p->prev = NULL;
      head = p;
    }
  }
  void printList()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
    }
    Node *p = head;
    do
    {
      cout << p->data << "\t";
      p = p->next;
    } while (p->next != 0);
    cout << "\n";
  }
  int countList()
  {
    int counter = 0;
    Node *p = head;
    do
    {
      counter++;
      p = p->next;
    } while (p->next != NULL);
    return counter;
  }
  int deleteFromHead()
  {
    int x;
    if (head == NULL) // case1
    {
      cout << "list Empty";
      exit(0);
    }
    else if (head->next == NULL) // case2 // only one node
    {
      x = head->data;
      delete head;
      head = NULL; // initalize head because list is empty now
      return x;
    }
    else // case3
    {
      Node *p = head;
      p->next->prev = NULL;
      head = head->next;
      x = p->data; // return data
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
      while (p->next != NULL)
      {  p = p->next; } ;
      x = p->data;
      p->prev->next = NULL;
      delete p;
      return x;
    }
  }
};

int main()
{
  DoublyLinkedList l;
  l.addToHead(5);
	l.addToHead(8);
	l.addToHead(9);
	cout<<"List Nodes: "<<l.countList()<<"  -->  ";
	l.printList();
	l.addToTail(4);
	l.addToTail(7);
	cout<<"List Nodes: "<<l.countList()<<"  -->  ";
	l.printList();
	
	l.deleteFromHead();
	cout<<"List Nodes: "<<l.countList()<<"  -->  ";
	l.printList();
	l.deleteFromTail();
	cout<<"List Nodes: "<<l.countList()<<"  -->  ";
	l.printList();

	return 0;
}