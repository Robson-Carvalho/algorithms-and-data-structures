#include <locale.h>
#include <stdio.h>
#include <string.h>

#define SIZE 50

struct person {
   char fullName[SIZE];
   char firstName[SIZE - 30];
   char lastName[SIZE - 30];
   int age;
};

typedef struct person person;

int main() {
   setlocale(LC_ALL, "Portuguese");

      person firstPerson = {"Robson Carvalho de Souza", "Robson", "Souza", 19};

   printf("Complete name: %s\n", firstPerson.fullName);
   printf("First name: %s\n", firstPerson.firstName);
   printf("Last name: %s\n", firstPerson.lastName);
   printf("Age: %d\n", firstPerson.age);

   strcpy(firstPerson.fullName, "Robson");

   printf("Age: %d\n", firstPerson.age);
}