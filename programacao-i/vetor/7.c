#include <stdio.h>
#include <stdlib.h>
#define ps 100
  void read(int array[], int us) {
    for(int i = 0; i < us; i++) {
      printf("Insert data to %d index os array: ", i);
      scanf("%d", &array[i]);
    } //for
  } //function read()
  void show(int array[], int us) {
    for(int i = 0; i < us; i++) {
      printf("The value on index %d is: %d.\n", i, array[i]);
    } //for
  } //function show()
  void search(int array[], int us, int num) {
    int pos = -1;
    for(int i = 0; i < us; i++) {
      if(array[i] == num) {
        printf("The number %d was found in array[%d].\n", num, i);
        pos = 0;
      } //if
    } //for
    if(pos == -1)
      printf("The number %d was not found in array.\n", num);
  } //function search()


  int main() {
    //entry numero da ação no menu
    //us tamanho usado do array
    //ps tamanho que o array pode ter
    int entry = 999, array[ps], array1[ps], us = 0, us1 = 0, num;

    while(entry != 0) {
      printf("MENU\n");
      printf("1 - Insert data in array[].\n");
      printf("2 - Insert data in array1[].\n");
      printf("3 - Show data in array[].\n");
      printf("4 - Show data in array1[].\n");
      printf("5 - Search data in array[].\n");
      printf("6 - Search data in array1[].\n");
      printf("0 - Leave.\n");
      printf("\nWhat you want to do? ");
      scanf("%d", &entry);
      switch(entry) {
        case 1:
          printf("Set the size of array[]: ");
          scanf("%d", &us);
          read(array, us);
            system("clear");
          break;
        case 2:
          printf("Set the size of array[]: ");
          scanf("%d", &us1);
          read(array1, us1);
          system("clear");
          break;
        case 3:
          show(array, us);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
          break;
        case 4:
          show(array1, us1);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
          break;
        case 5:
          printf("Insert the number to search in array: ");
          scanf("%d", &num);
          search(array, us, num);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
          break;
        case 6:
          printf("Insert the number to search in array: ");
          scanf("%d", &num);
          search(array1, us1, num);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
          break;
      } //switch
    } //while
  } //main
