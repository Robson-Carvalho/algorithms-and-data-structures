#include <iostream>
using namespace std;

// Function prototype - Using function before declaring its body
int multiplyNumbers(int x, int y);

int main()
{
  int num1 = 3, num2 = 7;
  int result = multiplyNumbers(num1, num2); // Calling the function
  cout << "The product is: " << result << endl;
  return 0;
}

// Function definition
int multiplyNumbers(int x, int y)
{
  int product = x * y;
  return product;
}