#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <windows.h>

#include "constantes.h"
#include "sequentiel.h"
#include "sequentiel.c"
#include "parallele.h"
#include "parallele.c"

int main() {
    HWND hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_MAXIMIZE);
    int choix,choix1;
    char foret[TAILLEX][TAILLEY];
    int nombreDeFeux;
    srand(time(NULL));
    //----------------------------- CHOIX DU MODE SEQUENTIEL OU PARALLELE ---------------------------
    do {
        system("cls");
        printf("Simulation de propagation du feu dans une foret\n");
        printf("Choisissez le mode d'execution:\n");
        printf("1. Mode Sequentiel\n");
        printf("2. Mode Parallele\n");
        printf("Votre choix: ");

        if (scanf("%d", &choix) != 1 || (choix != 1 && choix != 2)) {
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    system("cls");
    //--------------------------------- CREATION DES FEUX DANS LA FORET -----------------------------
    initialiserForet(foret);
    do {
        system("cls");
        afficherForet(foret);
        printf("1. Feux al%catoires\n",130);
        printf("2. Feux pr%cd%cfinis TEST\n",130,130);
        printf("Votre choix: ");

        if (scanf("%d", &choix1) != 1 || (choix1 != 1 && choix1 != 2)) {
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    if (choix1 == 1) {
        while (1) {
            printf("Combien de feux souhaitez-vous allumer ? ");
            if (scanf("%d", &nombreDeFeux) == 1 && nombreDeFeux > 0 && nombreDeFeux < TAILLEX * TAILLEY) {
               while (getchar() != '\n');
               break;
            } else {
               while (getchar() != '\n');
            }
        }
        for (int i = 0; i < nombreDeFeux; i++) {
            feuAleatoire(foret);
        }
    } else if (choix1 == 2) {
        feuTEST(foret);
        getchar() != '\n';
    }

    system("cls");
    afficherForet(foret);
    printf("Appuyez sur Entr%ce pour continuer...\n",130);
    getchar();
    //--------------------------------------------------------------------------------------
    if (choix == 1) {
        executerModeSequentiel(foret);
    } else if (choix == 2) {
        executerModeParallele(foret);
    }

    return 0;
}

