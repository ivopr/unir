#include <stdio.h>
#include <stdlib.h>
#define ps 100
  void ins(int array[], int ls) {
    for(int i = 0; i < ls; i++) {
      printf("Insert data to index[%d]: ", i);
      scanf("%d", &array[i]);
    } //for
  } //function read()
  void show(int array[], int ls) {
    for(int i = 0; i < ls; i++) {
      printf("The value on index[%d] is: %d.\n", i, array[i]);
    } //for
  } //function
  void insert(int array[], int ls, int num, int index) {
    for(int i = ls - 1; i >= index; i--) {
      array[i + 1] = array[i];
    }
      array[index] = num;
  } //function
  void delete(int array[], int ls, int index) {
    for(int i = index; i < ls - 1; i++) {
      array[i] = array[i + 1];
    }
  } //function
  int main() {
    //entry número da ação no menu
    //ls tamanho usado do array
    //ps tamanho que o array pode ter
    int entry = 999, array[ps], ls = 0, index, num;

    while(entry != 0) {
      printf("MENU\n");
      printf("1 - Insert main data in array.\n");
      printf("2 - Show data in array.\n");
      printf("3 - Insert data to a specific index of array.\n");
      printf("4 - Remove data from a specific index of array.\n");
      printf("0 - Leave.\n");
      printf("\nWhat you want to do? ");
      scanf("%d", &entry);
      switch(entry) {
        case 1:
          printf("Set the size of array: ");
          scanf("%d", &ls);
          ins(array, ls);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
          break;
        case 2:
          show(array, ls);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
          break;
        case 3:
        if(ls == ps) {
          printf("The array is full.\n");
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        } else {
          printf("What number you want to add? ");
          scanf("%d", &num);
          printf("What index you want to change? ");
          scanf("%d", &index);
          insert(array, ls, num, index);
          ls++;
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        } //if
          break;
        case 4:
        if(ls == 0) {
          printf("The array is untouched.\n");
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        } else {
          printf("What index you want to delete? ");
          scanf("%d", &index);
          delete(array, ls, index);
          ls--;
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        } //if
          break;
      } //switch
    } //while
  } //main
