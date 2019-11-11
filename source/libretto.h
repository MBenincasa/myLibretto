#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "esame.h"

#define MAX_BUFF 64
#define MAX_ESAMI 20

typedef struct libretto *libretto;

libretto readLibretto();
void addEsameInLibretto(libretto l, esame e);
void ordinePerVoto(libretto l);
void toStringLibretto(libretto l);
void ordineAlfabetico(libretto l);
void getMedia(libretto l);
