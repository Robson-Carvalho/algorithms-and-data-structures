/*Exercício 3: Soma de Números Pares
Escreva uma função que receba um número inteiro positivo n e retorne a soma dos
primeiros n números pares.*/

#include <stdio.h>

int sumPairs(int n) {
   int sum = 0;

   for (int i = 0; i <= n; i++) {
      if (i % 2 == 0) {
         sum += i;
      }
   }

   return sum;
}

int main() {
   int n;

   printf("Digite um número inteiro: ");
   scanf("%d", &n);

   int sum = sumPairs(n);

   printf("A soma dos %d números pares é %d\n", n, sum);
}