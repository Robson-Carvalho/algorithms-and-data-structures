#include <iostream>

int main() {
   int num = 42;         // 'num' é do tipo int de tipagem estática
   double pi = 3.14159;  // 'pi' e do tipo double de tipagem estática

   num = pi;  // 'num' vai assumir somente a parte inteira de pi.

   std::cout << "The value of num is: " << num << std::endl;
   std::cout << "The value of pi is: " << pi << std::endl;

   return 0;
}