#ifndef CONSTANTES_H
#define CONSTANTES_H

#define TAILLEX 40
#define TAILLEY 70
#define NBTHREAD 2

#define ARBRE 'T'
#define FEU 'F'
#define SLEEP 750

const int positionsEnFeu[][2] = {
    //{1, 3}, {4, 7}, {6, 1}, {9, 2}, {0, 8} // Pour la simulation 10 x 10
    //{9, 3}, {5, 6}, {11, 18}, {4, 18}, {18, 8} //Pour la simulation 20 x 20
    {7, 15}, {32, 28}, {12, 37}, {25, 5}, {38, 19} // Pour la simulation 40 x 40
    //{8, 22}, {45, 33}, {14, 56}, {29, 10}, {53, 40} // Pour la simulation 60 x 60
    //{12, 37}, {67, 54}, {33, 5}, {75, 22}, {24, 61} // Pour la simulation 80 x 80
};


#endif
