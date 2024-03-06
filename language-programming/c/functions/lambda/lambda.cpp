#include <iostream>
#include <vector>

using namespace std;

void functionLambda(void) {
   int x = 7;
   int y = 3;

   auto bigger = [](int x, int y) -> int { return (x > y) ? x : y; };

   std::cout << bigger(x, y) << std::endl;
}

void functionLambdaWithVector(void) {
   // verificando uma lista de inteiros e retornando o maior com função anônima
   auto biggerWithVector = [](vector<int> n) -> int {
      auto b = 0;

      for (int x : n) {

         b = (b > x) ? b : x;
      }
      return b;
   };

   std::cout << biggerWithVector({2, 5, 6, 7, 8, 9, 21, 4, 6}) << std::endl;
}

int main() {
   functionLambda();
   functionLambdaWithVector();

   int odd[5] = {1, 3, 5, 7, 9};

   // [=] - captura todas as variáveis do escopo.
   auto getAllVariablesTheScope = [=]() -> int {
      int sum = 0;

      for (int current : odd) {
         sum += current;
      };

      return sum;
   };

   std::cout << getAllVariablesTheScope() << std::endl;

   return 0;
}
