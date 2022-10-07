#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
  void read(int array[10]) {
    for(int i = 0; i < 10; i++) {
      printf("Insert array[%d]: ", i);
      scanf("%d", &array[i]);
      system("clear");
    }
  }
  void show(int array[10]) {
    for(int i = 0; i < 10; i++) {
      printf("array[%d]: %d\n", i, array[i]);
    }
  }
  bool symmetry(int array[10]) {
    for(int i = 0, j = 9; i < j; i++, j--) {
      if(array[i] != array[j])
        return false;
        else
          return true;
    }
  }
  int main() {
    int array[10];
    read(array);
    show(array);
    if(symmetry(array) == true)
      printf("The array is symmetric.\n");
      else {
        printf("The array isn't symmetric. It differs on:\n");
        for(int i = 0, j = 9; i < j; i++, j--) {
          if(array[i] != array[j]) {
            printf("array[%d]: %d - array[%d]: %d\n", i, array[i], j, array[j]);
          }
        }
      }
  return 0;
  }
