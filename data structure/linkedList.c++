#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class LinkedList
{
public:
  Node *head;
  LinkedList() { head = NULL; }
  bool isEmpty()
  {
    return (head == NULL);
  }
  void insertFirst(int newvalue)
  {
    Node *newNode = new Node(); // بوينتر من الكلاس نود
    newNode->data = newvalue;

    if (isEmpty())
    {
      newNode->next = NULL; // عشان لو الليست فاضية
      head = newNode;
    }
    else
    {
      newNode->next = head; // لو كان في فعلا في الليست بخلي النيكست بيساوي عنوان اول واحدة الي هي كانت الهيد
      head = newNode;       // بظبط الهيد الجديدة
    }
  }
  void display()
  {
    Node *temp = head; // عملت نود احتياطي بديل عن الهيد
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next; // عشان اخلي النود ينتقل للي بعده
    }
  }
  int counter()
  {
    int counter = 0; //initialize counter
    Node *temp = head; // عملت نود احتياطي بديل عن الهيد
    while (temp != NULL)
    {
      counter++;
      temp = temp->next; // عشان اخلي النود ينتقل للي بعده
    }
    return counter;
  }
  bool isFound(int key)
  {
    bool found = false;
    Node *temp = head; // عملت نود احتياطي بديل عن الهيد
    while (temp != NULL)
    {
      if (temp->data == key)
        found = true;
       else temp = temp->next;
    }
    return false; // fun is boolean
  }
};
int main()
{
  LinkedList list;
  if (list.isEmpty())
    cout << " list is empty ";
  else
    cout << " list contains " << list.counter();

  cout << "\n--------------------------------\n";

  for (int i = 0; i < 4; i++)
  {
    cout << "enter item to insert in the list : \n";
    int item;
    cin >> item;
    list.insertFirst(item);
  }
  cout << "After inserting items in the list : \n";
  list.display();
  cout << " after insert , list contains " << list.counter();

  cout << "\n enter item to search in the list : \n";
  int item;
  cin >> item;
  if (list.isFound(item))
    cout << "item found in the list ";
  else
    cout << "item not found in the list ";
    return 0;
}