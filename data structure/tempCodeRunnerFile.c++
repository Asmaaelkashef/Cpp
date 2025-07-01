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
  if (element == NU