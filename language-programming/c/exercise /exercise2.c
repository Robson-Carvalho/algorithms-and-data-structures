/*
Exercício 2: Verificação de Palíndromo
Crie um programa que verifique se uma palavra é um palíndromo (lê-se igual de
trás para frente).
*/

#include <stdio.h>

int main() {
   char word[] = "ovo";

   int count = 0;
   while (word[count]) {
      count += 1;
   }

   int middle = count / 2;

   int end = middle * 2;

   for (int i = 0; i < middle; i++) {
      if (word[i] != word[end - i]) {
         printf("%s não é palíndromo", word);
         return 0;
      }
   }

   printf("%s é palíndromo", word);

   return 0;
}