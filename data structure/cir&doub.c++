#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next, *prev;
  Node(int d = 0) : data(d), next(NULL), prev(NULL) {}
};
class CircularList {
public:
  Node *head, *tail;
  CircularList() : head(NULL), tail(NULL) {}
  ~CircularList() {
    if (head) {
      Node *temp = head;
      do {
        Node *del = temp;
        temp = temp->next;
        delete del;
      } while (temp != head); }}
  bool isEmpty() { return head == NULL; }
  void addToHead(int val) {
    Node *n = new Node(val);
    if (isEmpty()) head = tail = n, n->next = n;
    else n->next = head, head = n, tail->next = head;}
  void addToTail(int val) {
    Node *n = new Node(val);
    if (isEmpty()) head = tail = n, n->next = n;
    else tail->next = n, tail = n, tail->next = head;}
  int findNode(int val) {
    if (isEmpty()) return -1;
    Node *temp = head;
    int pos = 0;
    do {
      if (temp->data == val) return pos;
      temp = temp->next;
      pos++;
    } while (temp != head);
    return -1;}
  int deleteFromHead() {
    if (isEmpty()) return -1;
    int val = head->data;
    if (head == tail) { delete head; head = tail = NULL; }
    else {
      Node *temp = head;
      head = head->next;
      tail->next = head;
      delete temp;}
    return val;}
  int deleteFromTail() {
    if (isEmpty()) return -1;
    int val = tail->data;
    if (head == tail) { delete tail; head = tail = NULL; }
    else {
      Node *temp = head;
      while (temp->next != tail) temp = temp->next;
      temp->next = head;
      delete tail;
      tail = temp;}
    return val;}
  void deleteNode(int val) {
    if (isEmpty()) return;
    if (head->data == val) { deleteFromHead(); return; }
    Node *curr = head->next, *prev = head;
    while (curr != head) {
      if (curr->data == val) {
        prev->next = curr->next;
        if (curr == tail) tail = prev;
        delete curr;
        return;}
      prev = curr;
      curr = curr->next;}}
  void printList() {
    if (isEmpty()) { cout << "List is empty\n"; return; }
    Node *temp = head;
    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;  }
  void addNode(int pos, int val) {
    if (pos == 0) { addToHead(val); return; }
    Node *temp = head;
    for (int i = 0; temp->next != head && i < pos - 1; i++) temp = temp->next;
    Node *n = new Node(val);
    n->next = temp->next;
    temp->next = n;
    if (temp == tail) tail = n;}};
class DoublyList {
public:
  Node *head, *tail;
  DoublyList() : head(NULL), tail(NULL) {}
  ~DoublyList() {
    Node *temp = head;
    while (temp) {
      Node *del = temp;
      temp = temp->next;
      delete del;  }}
  bool isEmpty() { return head == NULL; }
  void addToHead(int val) {
    Node *n = new Node(val);
    if (isEmpty()) head = tail = n;
    else { n->next = head; head->prev = n; head = n; }}
  void addToTail(int val) {
    Node *n = new Node(val);
    if (isEmpty()) head = tail = n;
    else { tail->next = n; n->prev = tail; tail = n; }}
  int findNode(int val) {
    Node *temp = head;
    int pos = 0;
    while (temp) {
      if (temp->data == val) return pos;
      temp = temp->next;
      pos++;  }
    return -1;}
  int deleteFromHead() {
    if (isEmpty()) return -1;
    int val = head->data;
    if (head == tail) { delete head; head = tail = NULL; }
    else {
      Node *temp = head;
      head = head->next;
      head->prev = NULL;
      delete temp;}
    return val;}
  int deleteFromTail() {
    if (isEmpty()) return -1;
    int val = tail->data;
    if (head == tail) { delete tail; head = tail = NULL; }
    else {
      Node *temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete temp;}
    return val;}
  void deleteNode(int val) {
    if (isEmpty()) return;
    if (head->data == val) { deleteFromHead(); return; }
    if (tail->data == val) { deleteFromTail(); return; }
    Node *temp = head->next;
    while (temp) {
      if (temp->data == val) {
        temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        return;}
      temp = temp->next;}}
  void printList() {
    Node *temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;}
    cout << endl;}
  void addNode(int pos, int val) {
    if (pos == 0) { addToHead(val); return; }
    Node *temp = head;
    for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) { addToTail(val); return; }
    Node *n = new Node(val);
    n->next = temp->next;
    if (temp->next) temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
    if (temp == tail) tail = n;
  }};
int main() {
  CircularList cList;
  DoublyList dList;
  cList.addToHead(10); cList.addToTail(20); cList.addNode(1, 15);
  cout << "Circular List: "; cList.printList();
  cout << "Found 15 at position: " << cList.findNode(15) << endl;
  cList.deleteNode(15); cout << "After deleting 15: "; cList.printList();
  dList.addToHead(1); dList.addToTail(2); dList.addNode(1, 5);
  cout << "Doubly List: "; dList.printList();
  cout << "Found 5 at position: " << dList.findNode(5) << endl;
  dList.deleteNode(5); cout << "After deleting 5: "; dList.printList();
  return 0;
}
