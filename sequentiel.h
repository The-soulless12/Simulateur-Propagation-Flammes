#ifndef SEQUENTIEL_H
#define SEQUENTIEL_H

#include "constantes.h"

void initialiserForet(char foret[TAILLEX][TAILLEY]);
void afficherForet(char foret[TAILLEX][TAILLEY]);
void feuAleatoire(char foret[TAILLEX][TAILLEY]);
void feuTEST(char foret[TAILLEX][TAILLEY]);
void propagerFeu(char foret[TAILLEX][TAILLEY]);
int foretComplete(char foret[TAILLEX][TAILLEY]);
void executerModeSequentiel(char foret[TAILLEX][TAILLEY]);

#endif
