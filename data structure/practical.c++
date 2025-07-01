#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class list
{
public:
  Node *head;

  list()
  {
    head = NULL;
  }

  void addelementfirst(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }

  int deleteitem(int key)
  {
    int x;
    Node *p = head;
    Node *q ;

    while (p != NULL)
    {
      if (p->data == key)
      {
        x = p->data;
        if (p == head)
        {
          head = head->next;
        }
        else
        {
          q->next = p->next;
        }
        delete p;
        return x;
      }
      q = p;
      p = p->next;
    }

    return -1;
  }

  void printList()
  {
    Node *temp = head;
    if (temp == NULL)
    {
      cout << "List is empty\n";
      return;
    }

    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }
};

int computePwr(int base, int exponent)
{
  int result = 1;
  for (int i = 0; i < exponent; i++)
  {
    result *= base;
  }
  return result;
}

int main()
{
  // list List;
  // List.addelementfirst(5);
  // List.addelementfirst(2);
  // List.addelementfirst(3);

  // cout << "\nlist:\n";
  // List.printList();

  // List.deleteitem(5);

  // cout << "\nlist:\n";
  // List.printList();

  // int base, exponent;
  // cout << "\nEnter base to compute power: ";
  // cin >> base;
  // cout << "Enter exponent to compute power: ";
  // cin >> exponent;

  // int power = computePwr(base, exponent);
  // cout << "Result: " << power << endl;

 for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl; 
    }

  return 0;
}
