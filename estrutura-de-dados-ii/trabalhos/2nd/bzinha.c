#include "bzinha.h"

void insert(int key) {
  struct treeNode *newNode;
  int upKey;
  enum keyStatus value;

  value = ins(parent, key, &upKey, &newNode);

  if (value == D)
    printf("Key already available\n");

  if (value == II) {
    struct treeNode *upparent = parent;
    parent = malloc(sizeof(struct treeNode));
    parent->n = 1;
    parent->keys[0] = upKey;
    parent->p[0] = upparent;
    parent->p[1] = newNode;
  }
}

enum keyStatus ins(struct treeNode *ptr, int key, int *upKey, struct treeNode **newNode) {
  struct treeNode *newPtr, *lastPtr;
  int pos, i, n,splitPos;
  int newKey, lastKey;
  enum keyStatus value;
  if (ptr == NULL) {
    *newNode = NULL;
    *upKey = key;
    return II;
  }

  n = ptr->n;
  pos = searchPos(key, ptr->keys, n);

  if (pos < n && key == ptr->keys[pos]) return D;

  value = ins(ptr->p[pos], key, &newKey, &newPtr);

  if (value != II) return value;

  if (n < M - 1) {
    pos = searchPos(newKey, ptr->keys, n);

    for (i = n; i > pos; i--) {
      ptr->keys[i] = ptr->keys[i - 1];
      ptr->p[i + 1] = ptr->p[i];
    }

    ptr->keys[pos] = newKey;
    ptr->p[pos + 1] = newPtr;
    ++ptr->n;
    return S;
  }

  if (pos == M - 1) {
    lastKey = newKey;
    lastPtr = newPtr;
  } else {
    lastKey = ptr->keys[M - 2];
    lastPtr = ptr->p[M - 1];
    for (i = M - 2; i > pos; i--) {
      ptr->keys[i] = ptr->keys[i-1];
      ptr->p[i + 1] = ptr->p[i];
    }
    ptr->keys[pos] = newKey;
    ptr->p[pos + 1] = newPtr;
  }
  splitPos = (M - 1) / 2;
  (*upKey) = ptr->keys[splitPos];

  (*newNode) = malloc(sizeof(struct treeNode));
  ptr->n = splitPos;
  (*newNode)->n = M - 1 - splitPos;

  for (i = 0; i < (*newNode)->n; i++) {
    (*newNode)->p[i] = ptr->p[i + splitPos + 1];
    if(i < (*newNode)->n - 1)
      (*newNode)->keys[i] = ptr->keys[i + splitPos + 1];
    else
      (*newNode)->keys[i] = lastKey;
  }

  (*newNode)->p[(*newNode)->n] = lastPtr;
  return II;
}

int searchPos(int key, int *keyArray, int n) {
  int pos = 0;
  while (pos < n && key > keyArray[pos])
    pos++;
  return pos;
}

void display(struct treeNode *ptr, int blanks) {
  if (ptr) {
    int i;
    for(i = 1; i <= blanks; i++)
      printf(" ");
    for (i = 0; i < ptr->n; i++)
      printf("%d ",ptr->keys[i]);
    printf("\n");
    for (i = 0; i <= ptr->n; i++)
      display(ptr->p[i], blanks + 10);
  }
}

void inorder(struct treeNode *ptr) {
  if (ptr) {
    if (ptr->n >= 1) {
      inorder(ptr->p[0]);
      printf("%d ", ptr->keys[0]);
      inorder(ptr->p[1]);
      if (ptr->n == 2) {
        printf("%d ", ptr->keys[1]);
        inorder(ptr->p[2]);
      }
    }
  }
}

void postorder(struct treeNode *ptr) {
  if (ptr) {
    if (ptr->n >= 1) {
      postorder(ptr->p[0]);
      postorder(ptr->p[1]);
      printf("%d ", ptr->keys[0]);
      if (ptr->n == 2) {
        postorder(ptr->p[2]);
        printf("%d ", ptr->keys[1]);
      }
    }
  }
}

void preorder(struct treeNode *ptr) {
  if (ptr) {
    if (ptr->n >= 1) {
      printf("%d ", ptr->keys[0]);
      preorder(ptr->p[0]);
      preorder(ptr->p[1]);
      if (ptr->n == 2) {
        printf("%d ", ptr->keys[1]);
        preorder(ptr->p[2]);
      }
    }
  }
}

void destroy(struct treeNode *ptr) {
  if (ptr) {
    if (ptr->n >= 1) {
      destroy(ptr->p[0]);
      destroy(ptr->p[1]);
      free(ptr);
      if (ptr->n == 2) {
        destroy(ptr->p[2]);
        free(ptr);
      }
    }
  }
  treeReset();
}

void treeReset() {
  parent = NULL;
}
