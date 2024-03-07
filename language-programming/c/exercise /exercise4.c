/*Exercício 4: Fatorial
Implemente uma função para calcular o fatorial de um número.
*/
#include <stdio.h>

int factorial(int n) {
   if (n <= 2) {
      return n;
   }

   return n * factorial(n - 1);
}

int main() {
   int n = 0;

   printf("Digite um número inteiro: ");
   scanf("%d", &n);

   int fac = factorial(n);

   printf("%d! é igual a %d\n", n, fac);
}