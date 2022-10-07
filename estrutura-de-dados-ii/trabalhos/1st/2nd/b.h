#pragma once
#include <stdio.h>

# define D 5

typedef struct BTPagina {
  short int totalChaves;
  int chaves[D - 1];
  struct BTPage filha[D];
} Pagina;

typedef enum Status {

}
