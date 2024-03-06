#include <stdio.h>

int main() {
   int number = 0;
   int* numberP = &number;

   printf("%d\n", number);

   printf("Endereço na memória da variável number: ");
   printf("%p\n", (void*)&number);
   printf("Endereço na memória onde o ponteiro numberP está apontando: ");
   printf("%p\n", (void*)numberP);

   *numberP = 2;

   printf("%d", number);

   return 0;
}
