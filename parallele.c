#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include "parallele.h"
#include "constantes.h"
#include "sequentiel.h"

pthread_mutex_t mutexForet = PTHREAD_MUTEX_INITIALIZER;

void *propagerFeuParallele(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int debut = data->ligneDebut;
    int fin = data->ligneFin;
    int threadNum = data->threadNum;
    char foret[TAILLEX][TAILLEY];
    char foretTemp[TAILLEX][TAILLEY];

    memcpy(foret, data->foret, sizeof(char) * TAILLEX * TAILLEY);
    for (int i = 0; i < TAILLEX; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            foretTemp[i][j] = foret[i][j];
        }
    }

    for (int i = debut; i < fin; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            if (foret[i][j] == FEU) {
                if (i > 0 && foretTemp[i-1][j] == ARBRE)
                    foretTemp[i-1][j] = FEU;
                if (i < TAILLEX - 1 && foretTemp[i+1][j] == ARBRE)
                    foretTemp[i+1][j] = FEU;
                if (j > 0 && foretTemp[i][j-1] == ARBRE)
                    foretTemp[i][j-1] = FEU;
                if (j < TAILLEY - 1 && foretTemp[i][j+1] == ARBRE)
                    foretTemp[i][j+1] = FEU;
            }
        }
    }

    for (int i = 0; i < TAILLEX; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            foret[i][j] = foretTemp[i][j];
        }
    }
    memcpy( data->foret, foretTemp, sizeof(char) * TAILLEX * TAILLEY);

    pthread_exit(NULL);
}

void executerModeParallele(char foret[TAILLEX][TAILLEY]) {
    int lignesParThread = TAILLEX / NBTHREAD;
    pthread_t threads[NBTHREAD];
    ThreadData threadData[NBTHREAD];

    clock_t start = clock();
    clock_t end = clock();
    int cpt = 0;

    start = clock();
    while (!foretComplete(foret)) {
         system("cls");
         for (int j = 0; j < NBTHREAD; j++) {
            threadData[j].foret = foret;
            threadData[j].threadNum = j;
            threadData[j].ligneDebut = j * lignesParThread;
            threadData[j].ligneFin = (j == NBTHREAD - 1) ? TAILLEX : (j + 1) * lignesParThread;
            if (pthread_create(&threads[j], NULL, propagerFeuParallele, &threadData[j]) != 0) {
               perror("Erreur de création du thread");
               exit(EXIT_FAILURE);
            }
         }
         for (int j = 0; j < NBTHREAD; j++) {
             pthread_join(threads[j], NULL);
         }
         afficherForet(foret);
         Sleep(SLEEP);
         cpt++;
    }
    end = clock();
    printf("Tous les arbres sont en feu !\n");
    printf("Temps parall%cle: %f secondes\n",138, (double)(end - start - cpt*SLEEP) / CLOCKS_PER_SEC);
}
