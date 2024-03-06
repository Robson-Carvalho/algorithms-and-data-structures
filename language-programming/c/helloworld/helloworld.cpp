#include <iostream>

int main() {
   int number = 0;
   int& numberR = number;

   printf("%d\n", number);

   numberR = 2;

   printf("%d", number);

   return 0;
}
