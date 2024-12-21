#ifndef PARALLELE_H
#define PARALLELE_H

#include "constantes.h"

typedef struct {
    char (*foret)[TAILLEX][TAILLEY]; //Chaque thread va pointer sur la forêt
    int threadNum;
    int ligneDebut;
    int ligneFin;
} ThreadData;

void executerModeParallele(char foret[TAILLEX][TAILLEY]);

#endif
