#include <stdio.h>
#include <stdlib.h>

int main() {
   int size;
   int *array, sum;

   printf("Digite a quantidade de notas: ");
   scanf("%d", &size);

   array = (int *)malloc(size * sizeof(int));

   if (array == NULL) {
      fprintf(stderr, "Erro ao alocar memória.\n");
      return 1;
   }

   printf("\nDigite as notas\n");
   for (int i = 0; i < size; i++) {
      printf("Nota %d: ", i + 1);
      scanf("%d", &array[i]);
   }

   for (int i = 0; i < size; i++) {
      sum += array[i];
   }

   sum = sum / size;

   printf("\nA média é %.2f\n", sum);

   free(array);
}
