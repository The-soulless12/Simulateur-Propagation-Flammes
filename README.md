# Simulateur-Propagation-Flammes
Simulateur d'incendie forestier en langage C, offrant une exécution séquentielle et parallèle grâce à la bibliothèque pthreads afin de comparer les performances et modéliser la propagation du feu.

# Fonctionnalités
- Simulation d'un incendie.
- Mode séquentiel.
- Mode parallèle.

# Structure du projet
- constantes.h : Définition des constantes utilisées dans la simulation (par exemple, la taille de la grille, les paramètres de propagation du feu, etc.).
- main.c : Point d'entrée du programme, où l'utilisateur peut choisir entre les modes séquentiel et parallèle.
- parallele.c : Implémentation des fonctions permettant l'exécution parallèle de la simulation à l'aide de la bibliothèque pthreads.
- parallele.h : Déclarations des fonctions et structures utilisées pour la version parallèle.
- sequentiel.c : Implémentation de la version séquentielle de la simulation.
- sequentiel.h : Déclarations des fonctions et structures utilisées pour la version séquentielle.

# Prérequis 
- Compilateur C.
