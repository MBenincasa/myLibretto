#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFF 64

typedef struct esame *esame;

esame insertEsame();
esame newEsame(char *nome, int voto, char lode, int crediti);
void toStringEsame(esame e);
char *getNomeEsame(esame e);
int getVotoEsame(esame e);
char getLodeEsame(esame e);
int getCreditiEsame(esame e);
