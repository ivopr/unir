#include <stdio.h>
#include <stdlib.h>
  void read(int array[10], int array1[10]) {
    for(int i = 0; i < 10; i++) {
      printf("Insert data to array[%d]: ", i);
      scanf("%d", &array[i]);
      system("clear");
    }
    for(int i = 0; i < 10; i++) {
      printf("Insert data to array1[%d]: ", i);
      scanf("%d", &array1[i]);
      system("clear");
    }
  }
  int readnum(int num) {
    printf("Insert data to num var: ");
    scanf("%d", &num);
  return num;
  }
  void show(int array[10], int array1[10]) {
    for(int i = 0; i < 10; i++) {
      printf("Data on array[%d]: %d\n", i, array[i]);
    }
    for(int i = 0; i < 10; i++) {
      printf("Data on array1[%d]: %d\n", i, array1[i]);
    }
  }
  void check(int array[10], int array1[10], int num) {
    int pos = -1;
    for(int i = 0; i < 10; i++) {
      if(array[i] == num) {
        printf("The number %d was found in array[%d].\n", num, i);
        pos = 0;
      }
      if(array1[i] == num) {
        printf("The number %d was found in array1[%d].\n", num, i);
        pos = 0;
      }
    }
    if(pos == -1)
      printf("The number %d was not found in array.\n", num);
  }
  int main() {
    int array[10], array1[10], num;
    read(array, array1);
    show(array, array1);
    num = readnum(num);
    while(num != 999) {
      check(array, array1, num);
      num = readnum(num);
    }
  return 0;
  }
