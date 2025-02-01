#include <iostream>

int factorial(int num)
{
  if(num == 0 || num == 1) return 1 ; // base case
  else return num * factorial(num - 1); 
}

int main()
{
  int num;
  std::cout << "Enter a number: ";
  std::cin >> num;
  std::cout << "Factorial of " << num << " is: " << factorial(num) << std::endl;
  return 0; 
}