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

// طباعة الشجرة باستخدام الـ Postorder Traversal: (الفرع الأيسر → الفرع الأيمن → الجذر)
void printPostorder(Node *element)
{
  if (element == NULL)
    return;

  printPostorder(element->left);  // طباعة الفرع الأيسر
  printPostorder(element->right); // طباعة الفرع الأيمن
  cout << element->data << "\t";  // طباعة الجذر
}

// طباعة الشجرة باستخدام الـ Preorder Traversal: (الجذر → الفرع الأيسر → الفرع الأيمن)
void printPreorder(Node *element)
{
  if (element == NULL)
    return;

  cout << element->data << "\t"; // طباعة الجذر
  printPreorder(element->left);  // طباعة الفرع الأيسر
  printPreorder(element->right); // طباعة الفرع الأيمن
}

// طباعة الشجرة باستخدام الـ Inorder Traversal: (الفرع الأيسر → الجذر → الفرع الأيمن)
// بتفيد في ترتيب العناصر تصاعدياً في شجرة البحث الثنائية
void printinorder(Node *element)
{
  if (element == NULL)
    return;

  printinorder(element->left);   // طباعة الفرع الأيسر
  cout << element->data << "\t"; // طباعة الجذر
  printinorder(element->right);  // طباعة الفرع الأيمن
}

// حساب عدد العقد (العناصر) في الشجرة
int treeSize(Node *element)
{
  if (element == NULL)
    return 0;

  // 1 تمثل العنصر الحالي + العناصر في اليسار + العناصر في اليمين
  return 1 + treeSize(element->left) + treeSize(element->right);
}

// حساب أقصى عمق (طول المسار من الجذر لأبعد عقدة)
int treeDepth(Node *element)
{
  if (element == NULL)
    return 0;

  int x, y;
  x = treeDepth(element->left);  // عمق الفرع الأيسر
  y = treeDepth(element->right); // عمق الفرع الأيمن

  // نرجّع الأكبر + 1 علشان نحسب الجذر الحالي
  if (x > y)
    return 1 + x;
  else
    return 1 + y;
}

// إدخال عنصر جديد بطريقة recursive
Node *insert(Node *element, int data)
{
  if (element == NULL) // لو الشجرة فاضية أو وصلنا لمكان الإدخال
  {
    element = new Node;    // إنشاء عقدة جديدة
    element->data = data;  // وضع القيمة
    element->left = NULL;  // لا يوجد فرع أيسر
    element->right = NULL; // لا يوجد فرع أيمن
    return element;        // إرجاع العنصر الجديد
  }

  // لو القيمة أصغر أو تساوي الجذر، ندخلها في الفرع الأيسر
  if (data <= element->data)
  {
    element->left = insert(element->left, data);
  }
  else // لو أكبر، ندخلها في الفرع الأيمن
  {
    element->right = insert(element->right, data);
  }

  return element; // إرجاع الجذر بعد التعديل
}

// إدخال عنصر جديد بطريقة iterative (بدون recursion)
Node *insert_iterative(Node *element, int d)
{
  Node *newnode = new Node(d); // إنشاء عقدة جديدة

  if (element == NULL) // لو الشجرة فاضية
  {
    return newnode;
  }

  Node *p = element;   // مؤشر للمشي داخل الشجرة
  Node *parent = NULL; // لحفظ الأب المؤقت

  // البحث عن المكان المناسب للإدخال
  while (p != NULL)
  {
    parent = p;

    if (d <= p->data)
      p = p->left;
    else
      p = p->right;
  }

  // ربط العنصر الجديد كفرع يسار أو يمين
  if (d <= parent->data)
    parent->left = newnode;
  else
    parent->right = newnode;

  return element; // إرجاع الجذر بعد الإدخال
}

// إرجاع أصغر عقدة في الشجرة (أقصى اليسار)
Node *treeMinNode(Node *element)
{
  Node *p = element;

  while (p && p->left != NULL) // نذهب لأقصى اليسار
    p = p->left;

  return p;
}

// إرجاع أكبر عقدة في الشجرة (أقصى اليمين)
Node *treeMaxNode(Node *element)
{
  Node *p = element;

  while (p && p->right != NULL) // نذهب لأقصى اليمين
    p = p->right;

  return p;
}

// حذف عقدة من الشجرة (حسب 3 حالات)
Node *deleteNode(Node *r, int d)
{
  if (r == NULL)
    return r;

  // البحث عن العنصر
  if (d < r->data)
    r->left = deleteNode(r->left, d);
  else if (d > r->data)
    r->right = deleteNode(r->right, d);
  else // تم العثور على العقدة
  {
    // الحالة 1: العنصر لا يملك أبناء (ورقة)
    if (r->left == NULL && r->right == NULL)
    {
      delete r;
      return NULL;
    }

    // الحالة 2: العنصر يملك فرع واحد فقط
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

    // الحالة 3: العنصر لديه فرعين
    Node *p = treeMinNode(r->right);          // إيجاد أصغر عنصر في اليمين
    r->data = p->data;                        // نسخ قيمته
    r->right = deleteNode(r->right, p->data); // حذف النسخة الأصلية
  }

  return r; // إرجاع الجذر بعد التعديل
}

// إرجاع أصغر قيمة (بدون إرجاع العقدة، فقط القيمة)
int treeMin(Node *element)
{
  Node *current = element;

  while (current->left != NULL) // نمشي لأقصى اليسار
  {
    current = current->left;
  }

  return (current->data);
}

// إرجاع أكبر قيمة (بدون إرجاع العقدة، فقط القيمة)
int treeMax(Node *element)
{
  Node *current = element;

  while (current->right != NULL) // نمشي لأقصى اليمين
  {
    current = current->right;
  }

  return (current->data);
}

int main()
{
  Node *root = new Node(10);

  insert_iterative(root, 3);
  insert_iterative(root, 11);
  insert_iterative(root, 20);
  insert_iterative(root, 6);
  insert_iterative(root, 5);

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
  deleteNode(root, 3);
  cout << "\nInorder  : ";
  printinorder(root);
  cout << "\nTree Size: " << treeSize(root);
}
