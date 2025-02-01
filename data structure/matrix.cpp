#include <iostream>
using namespace std;

// دالة جمع المصفوفات
void sumMatrix(int rows, int columns, int** arrayA, int** arrayB, int** arrayC)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
        cout << "Enter elements of matrix A :";
        cin >> arrayA[i][j];
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      cout << "Enter elements of matrix B :";
        cin >> arrayB[i][j];
      arrayC[i][j] = arrayA[i][j] + arrayB[i][j];
    }
  }

  cout << "The sum of the two matrices is:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      cout << arrayC[i][j] << " ";
    }
    cout << endl;
  }
}

// دالة ضرب المصفوفات
void multiMatrix(int rowsA, int colsA, int colsB, int** arrayA, int** arrayB, int** arrayC)
{
  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < colsA; j++)
    {
      cout << "Enter elements of matrix A :";
      cin >> arrayA[i][j];
    }
  }

  for (int i = 0; i < colsA; i++)
  {
    for (int j = 0; j < colsB; j++)
    {
      cout << "Enter elements of matrix B :";
      cin >> arrayB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < colsB; j++)
    {
      arrayC[i][j] = 0; 
      for (int k = 0; k < colsA; k++)
      {
        arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
      }
    }
  }

  cout << "The product of the two matrices is:\n";
  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < colsB; j++)
    {
      cout << arrayC[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int rowsA, colsA, rowsB, colsB, choice;

  cout << "Enter 1 for addition or 2 for multiplication: ";
  cin >> choice;

  if (choice == 1)
  {
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rowsA >> colsA;
  
    int** arrayA = new int*[rowsA];
    int** arrayB = new int*[rowsA];
    int** arrayC = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
      arrayA[i] = new int[colsA];
      arrayB[i] = new int[colsA];
      arrayC[i] = new int[colsA];
    }

    
    sumMatrix(rowsA, colsA, arrayA, arrayB, arrayC);


    for (int i = 0; i < rowsA; i++)
    {
      delete[] arrayA[i];
      delete[] arrayB[i];
      delete[] arrayC[i];
    }
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
  }
  else if (choice == 2)
  {
    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowsB >> colsB;

    while (colsA != rowsB)
    {
      cout << "Error: The number of columns in A must be equal to the number of rows in B!\n";
      cout << "Enter the number of rows and columns for matrix A: ";
      cin >> rowsA >> colsA;
      cout << "Enter the number of rows and columns for matrix B: ";
      cin >> rowsB >> colsB;
    }

    int** arrayA = new int*[rowsA];
    int** arrayB = new int*[rowsB];
    int** arrayC = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
      arrayA[i] = new int[colsA];
    for (int i = 0; i < rowsB; i++)
      arrayB[i] = new int[colsB];
    for (int i = 0; i < rowsA; i++)
      arrayC[i] = new int[colsB];


    multiMatrix(rowsA, colsA, colsB, arrayA, arrayB, arrayC);

    for (int i = 0; i < rowsA; i++) delete[] arrayA[i];
    for (int i = 0; i < rowsB; i++) delete[] arrayB[i];
    for (int i = 0; i < rowsA; i++) delete[] arrayC[i];
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
  }
  else
  {
    cout << "Invalid choice!";
  }

  return 0;
}
