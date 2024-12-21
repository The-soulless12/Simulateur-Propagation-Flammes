#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "sequentiel.h"
#include "constantes.h"

void initialiserForet(char foret[TAILLEX][TAILLEY]) {
    for (int i = 0; i < TAILLEX; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            foret[i][j] = ARBRE;
        }
    }
}

void afficherForet(char foret[TAILLEX][TAILLEY]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < TAILLEX; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            if (foret[i][j] == ARBRE) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("%c ", foret[i][j]);
            } else if (foret[i][j] == FEU) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("%c ", foret[i][j]);
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                printf("%c ", foret[i][j]);
            }
        }
        printf("\n");
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
}

void feuAleatoire(char foret[TAILLEX][TAILLEY]) {
    int x, y;

    do {
        x = rand() % TAILLEX;
        y = rand() % TAILLEY;
    } while (foret[x][y] == FEU);

    foret[x][y] = FEU;
}

void feuTEST(char foret[TAILLEX][TAILLEY]) {
    int nombrePositionsEnFeu = sizeof(positionsEnFeu) / sizeof(positionsEnFeu[0]);

    for (int i = 0; i < nombrePositionsEnFeu; i++) {
        int x = positionsEnFeu[i][0];
        int y = positionsEnFeu[i][1];

        if (x >= 0 && x < TAILLEX && y >= 0 && y < TAILLEY) {
            foret[x][y] = FEU;
        }
    }
}

void propagerFeu(char foret[TAILLEX][TAILLEY]) {
    char foretTemp[TAILLEX][TAILLEY];

    for (int i = 0; i < TAILLEX; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            foretTemp[i][j] = foret[i][j];
        }
    }

    for (int i = 0; i < TAILLEX; i++) {
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
}

int foretComplete(char foret[TAILLEX][TAILLEY]) {
    for (int i = 0; i < TAILLEX; i++) {
        for (int j = 0; j < TAILLEY; j++) {
            if (foret[i][j] == ARBRE) {
                return 0;
            }
        }
    }
    return 1;
}

void executerModeSequentiel(char foret[TAILLEX][TAILLEY]) {
    clock_t start = clock();
    clock_t end = clock();
    int cpt = 0;

    start = clock();
    while (!foretComplete(foret)) {
        system("cls");
        propagerFeu(foret);
        afficherForet(foret);
        Sleep(SLEEP);
        cpt ++;
    }
    end = clock();
    printf("Tous les arbres sont en feu !\n");
    printf("Temps s%cquentiel: %f secondes\n",130, (double)(end - start - cpt*SLEEP) / CLOCKS_PER_SEC);
}
