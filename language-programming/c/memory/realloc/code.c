#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
   float *notas = NULL;
   int count = 0;
   float nota;

   bool condition = true;

   while (condition) {
      printf("Digite a nota: ");
      scanf("%f", &nota);

      if (nota < 0) {
         condition = false;
      } else {
         notas = realloc(notas, (count + 1) * sizeof(float));

         if (notas == NULL) {
            fprintf(stderr, "Falha na alocação de memória\n");
            return 1;
         }

         printf("\nEndereço virtual da memória alocada na repetição %d: %p\n\n",
                count + 1, (void *)&notas[count]);

         notas[count] = nota;
         count++;
      }
   }

   if (count == 0) {
      printf("Nenhuma nota inserida. Não é possível calcular a média.\n");
   } else {
      float sum = 0;

      for (int i = 0; i < count; i++) {
         sum += notas[i];
      }

      float media = sum / count;

      printf("A média é: %.2f\n", media);
   }

   free(notas);

   return 0;
}
