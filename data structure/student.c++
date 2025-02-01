#include <iostream>
#include <string.h>
using namespace std;

struct student
{
    string name;
    int age;
    int grade;
    float gpa;
};

struct teacher
{
  string name;
  int age;
  int subjectID;
  string subjectName;
  float salary;
};

int main()
{
  struct student Student[5];
  struct teacher Teacher[5];
  
  for (int i = 0; i < 5; i++)
  {
    cout << "Enter student's name: ";
    cin >> Student[i].name;
    cout << "Enter student's age: ";
    cin >> Student[i].age;
    cout << "Enter student's grade: ";
    cin >> Student[i].grade;
    cout << "Enter student's GPA: ";
    cin >> Student[i].gpa;
    cout << endl;
  }

  for (int i = 0; i < 5; i++)
  {
    cout << "Enter teacher's name: ";
    cin >> Teacher[i].name;
    cout << "Enter teacher's age: ";
    cin >> Teacher[i].age;
    cout << "Enter teacher's subject ID: ";
    cin >> Teacher[i].subjectID;
    cout << "Enter teacher's subject name: ";
    cin >> Teacher[i].subjectName;
    cout << "Enter teacher's salary: ";
    cin >> Teacher[i].salary;
    cout << endl;
  }

  cout << "Student Information:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "Name: " << Student[i].name << endl;
    cout << "Age: " << Student[i].age << endl;
    cout << "Grade: " << Student[i].grade << endl;
    cout << "GPA: " << Student[i].gpa << endl;
    cout << endl;
  }

  cout << "Teacher Information:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "Name: " << Teacher[i].name << endl;
    cout << "Age: " << Teacher[i].age << endl;
    cout << "Subject ID: " << Teacher[i].subjectID << endl;
    cout << "Subject Name: " << Teacher[i].subjectName << endl;
    cout << "Salary: " << Teacher[i].salary << endl;
    cout << endl;
  }
}