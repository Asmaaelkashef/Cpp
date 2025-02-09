#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left, *right;
  Node()
  {
    data = 0;
    left = right = NULL;
  }
  Node(int d)
  {
    data = d;
    left = right = NULL;
  }
};

void printPostorder(Node *element)
{
  if (element == NULL)
    return;
  printPostorder(element->left);
  printPostorder(element->right);
  cout << element->data << "\t";
}

void printPreorder(Node *element)
{
  if (element == NULL)
    return;
  cout << element->data << "\t";
  printPreorder(element->left);
  printPreorder(element->right);
}

void printinorder(Node *element)
{
  if (element == NULL)
    return;
  printinorder(element->left);
  cout << element->data << "\t";
  printinorder(element->right);
}
int treeSize(Node *element)
{
  if (element == NULL)
    return 0;
  return 1 + treeSize(element->left) + treeSize(element->right);
}
int treeDepth(Node *element)
{
  if (element == NULL)
    return 0;
  int x, y;
  x = treeDepth(element->left);
  y = treeDepth(element->right);
  if (x > y)
    return 1 + x;
  else
    return 1 + y;
}
Node *insert(Node *element, int data) // recursion
{
  if (element == NULL)
  {
    element = new Node;
    element->data = data;
    element->left = NULL;
    element->right = NULL;
    return element;
  }
  if (data <= element->data)
  {
    element->left = insert(element->left, data);
  }
  else
  {
    element->right = insert(element->right, data);
  }
  return element;
}
Node *insert_iterative(Node *element, int d)
{
  Node *newnode = new Node(d);
  if (element == NULL)
  {
    return newnode;
  }
  Node *p = element;
  Node *parent = NULL;

  while (p != NULL)
  {
    parent = p;
    if (d <= p->data)
      p = p->left;
    else
      p = p->right;
  }
  if (d <= parent->data)
    parent->left = newnode;
  else
    parent->right = newnode;

  return element;
}
Node *treeMinNode(Node *element)
{
  Node *p = element;
  while (p && p->left != NULL)
    p = p->left;

  return p;
}
Node *treeMaxNode(Node *element)
{
  Node *p = element;
  while (p && p->right != NULL)
    p = p->right;

  return p;
}
Node *deleteNode(Node *r, int d)
{
  if (r == NULL)
    return r;
  if (d < r->data) // find element
    r->left = deleteNode(r->left, d);
  else if (d > r->data) // find element
    r->right = deleteNode(r->right, d);
  else // cases
  {
    if (r->left == NULL && r->right == NULL) // leaf
    {
      delete r;
      return NULL;
    }
    // node with only one child or no child
    if (r->left == NULL)
    {
      Node *p = r->right;
      delete r;
      return p;
    }
    else if (r->right == NULL)
    {
      Node *p = r->left;
      delete r;
      return p;
    }
    Node *p = treeMinNode(r->right); // 2 child
    r->data = p->data;
    r->right = deleteNode(r->right, p->data);
  }
  return r;
}
int treeMin(Node *element)
{
  Node *current = element;
  while (current->left != NULL)
  {
    current = current->left;
  }
  return (current->data);
}

int treeMax(Node *element)
{
  Node *current = element;
  while (current->right != NULL)
  {
    current = current->right;
  }
  return (current->data);
}
int main()
{
    Node *root=new Node(10);

    insert_iterative(root,3);
    insert_iterative(root,11);
    insert_iterative(root,20);
    insert_iterative(root,6);
    insert_iterative(root,5);

    cout << "\nPostorder: ";
    printPostorder(root);
    cout << "\nPreorder : ";
    printPreorder(root);
    cout << "\nInorder  : ";
    printinorder(root);

    cout << "\nTree Size: " << treeSize(root);
    cout << "\nTree Depth: " << treeDepth(root);
    cout << "\nTree Minimum Value: " << treeMin(root);
    cout << "\nTree Maximum Value: " << treeMax(root);
    deleteNode(root,3);
    cout << "\nInorder  : ";
    printinorder(root);
    cout << "\nTree Size: " << treeSize(root);

}
