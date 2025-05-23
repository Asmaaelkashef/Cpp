#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next, *prev;
  Node() { next = prev = 0; }
  Node(int d) { data = d; next = prev = 0; }};
class Doubly_List {
public:
  Node *head;
  Doubly_List() { head = NULL; }
  ~Doubly_List() {
    Node *p;
    while (head != NULL) {
      p = head;
      head = head->next;
      delete p;
    }}
  bool isEmpty() { return head == NULL; }
  void addToHead(int item) {
    Node *p = new Node(item);
    p->next = head;
    if (head != NULL) head->prev = p;
    head = p;}
  void addToTail(int item) {
    Node *p = new Node(item);
    if (head == NULL) { head = p; return; }
    Node *q = head;
    while (q->next != NULL) q = q->next;
    q->next = p;
    p->prev = q;}
  int findNode(int item) {
    Node *p = head;
    int pos = 0;
    while (p != NULL) {
      if (p->data == item) return pos;
      p = p->next;
      pos++;}
    return -1;}
  int deleteFromHead() {
    if (head == NULL) { cout << "List Empty"; exit(0); }
    int x = head->data;
    Node *p = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete p;
    return x;}
  int deleteFromTail() {
    if (head == NULL) { cout << "List Empty"; exit(0); }
    Node *p = head;
    if (p->next == NULL) {
      int x = p->data;
      delete p;
      head = NULL;
      return x;}
    while (p->next != NULL) p = p->next;
    int x = p->data;
    p->prev->next = NULL;
    delete p;
    return x;}
  void deleteNode(int item) {
    if (head == NULL) { cout << "List Empty"; return; }
    if (head->data == item) { deleteFromHead(); return; }
    Node *p = head->next;
    while (p != NULL) {
      if (p->data == item) {
        p->prev->next = p->next;
        if (p->next != NULL) p->next->prev = p->prev;
        delete p;
        return;
      }
      p = p->next;
    }}
  void printList() {
    Node *p = head;
    while (p != NULL) {
      cout << p->data << "\t";
      p = p->next;}
    cout << endl;
  }};
int main() {
  Doubly_List l;
  l.addToHead(5);
  l.addToHead(8);
  l.addToHead(9);
  cout << "List: "; l.printList();
  l.addToTail(4);
  l.addToTail(7);
  cout << "List: "; l.printList();
  l.deleteFromHead();
  cout << "List: "; l.printList();
  l.deleteFromTail();
  cout << "List: "; l.printList();
  cout << "Find 5 at position: " << l.findNode(5) << endl;
  l.deleteNode(5);
  cout << "List: "; l.printList();
  return 0;
}
