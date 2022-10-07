/***************************************************************
* Students: Murilo Fuza da Cunha & Ivo Henrique
* Course: Bachelor of Computer Science
* Teacher: Carolina Yukari Veludo Watanabe
*
* DS2 Project - BTree
*
* Compiler: gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
* Operacional System: Windows 10 Pro
*
* Use the code at will, we just ask you to reference us the creators in their academic work
***************************************************************/

#include "bzinha.h"

int main() {
  int key;
  int choice, choiceDisplay;
  printf("B-Tree order: %d\n", M);

  while(1) {
    system("cls");
    printf("1.Reset Tree\n");
    printf("2.Insert\n");
    printf("3.Display (Submenu)\n");
    printf("4.Kaboom!\n");
    printf("5.Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

      switch(choice) {
      case 1:
        treeReset(parent);
        printf("Tree reseted\n");
        system("pause");
        break;
      case 2:
        printf("Enter the key: ");
        scanf("%d", &key);
        insert(key);
        break;
      case 3:
        while(choiceDisplay != 5) {
          system("cls");
          printf("1.In Order\n");
          printf("2.Pre Order\n");
          printf("3.Post Order\n");
          printf("4.Tree\n");
          printf("5.Back\n");
          printf("Choice: ");
          scanf("%d", &choiceDisplay);

          switch(choiceDisplay) {
          case 1:
            inorder(parent);
            printf("\n");
            system("pause");
            break;
          case 2:
            preorder(parent);
            printf("\n");
            system("pause");
            break;
          case 3:
            postorder(parent);
            printf("\n");
            system("pause");
            break;
          case 4:
            display(parent, 0);
            system("pause");
            break;
          default:
            printf("wait... that's illegal...\n");
            break;
          }
        }
        choiceDisplay = 0;
        break;
      case 4:
        destroy(parent);
        printf("tree... kaboom...\n");
        system("pause");
        break;
      case 5:
        exit(1);
      default:
        printf("wait... that's illegal...\n");
        system("pause");
        break;
      }/*End of switch*/
  }/*End of while*/
  return 0;
}/*End of main()*/
