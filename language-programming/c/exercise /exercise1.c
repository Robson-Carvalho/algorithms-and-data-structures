/*Exercício 1: Trocar Valores
Escreva um programa que troque os valores de duas variáveis inteiras sem usar
uma variável temporária.
*/

#include <stdio.h>

int main() {
   int x = 5;
   int y = 3;

   printf("Valores originais:\nx = %d\ny = %d", x, y);

   x = x ^ y;
   y = x ^ y;
   x = x ^ y;

   printf("\n\nValores alterados:\nx = %d\ny = %d", x, y);

   return 0;
}