#include <stdlib.h>

typedef struct letra {
  char c;
  struct letra *prox;
} Letra;

Letra *criaPalavra();
int addLetra(Letra *L, char c);
char pickLetra(Letra *L, int pos);
int printPalavra(Letra *L);

int trCesar(Letra *L);
int trChave(Letra *L);
