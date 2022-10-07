#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define M 3

struct treeNode {
  int n, keys[M - 1];
  struct treeNode *p[M];
};

struct treeNode *parent;

// Duplicate, Search Failure, Success, Insert It, Less Keys
enum keyStatus {D, SF, S, II, LK};

void insert(int);
enum keyStatus ins(struct treeNode*, int, int*, struct treeNode**);
int searchPos(int, int*, int);
void display(struct treeNode*, int);
void inorder(struct treeNode*);
void preorder(struct treeNode*);
void postorder(struct treeNode*);
void treeReset();
void destroy(struct treeNode*);
