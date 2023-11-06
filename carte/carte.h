//
// Created by yweng on 16/10/2023.
//

#ifndef DOOMDEPTHSC_CARTE_H
#define DOOMDEPTHSC_CARTE_H
#include <stdio.h>
#include "../Joueur/joueur.h"

typedef struct {

    char * nom;
    int xMax;
    int yMax;
    int carte[11][11];
}Map;
extern Map maison;
extern Map zone1;
extern Map zone2;

extern int joueurX, joueurY;
extern Map carteActuel;
void afficherMap(Map map);
int mouvementPossible(int newX, int newY);
void bouger(char input, Joueur *heros);
void changerCarte(char input);
void evenementMap(Joueur* heros);

#endif //DOOMDEPTHSC_CARTE_H
