#include <stdio.h>

void addFive(int* d) { (*d) += 5; }

int main() {
   int number = 0;
   int* numberR = &number;

   printf("%d\n", number);

   *numberR = 2;

   printf("%d\n", number);

   addFive(numberR);

   printf("%d\n", number);

   addFive(&number);

   printf("%d\n", number);

   printf("%p", numberR);

   return 0;
}
