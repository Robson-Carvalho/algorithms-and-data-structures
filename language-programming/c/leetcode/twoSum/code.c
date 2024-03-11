#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int x = 0;
   int y = 0;

   for (int i = 0; i < numsSize; i++) {
      for (int j = 1; j < numsSize; j++) {
         if (nums[i] + nums[j] == target) {
            x = i;
            y = j;
            break;
         }
      }
   }

   return x, y;
}

int main() {
   int a[] = {2, 3, 5};
   twoSum(a, 3, 7, 0);
}