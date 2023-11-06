#ifndef MONSTRE_H
#define MONSTRE_H
#include "../Joueur/joueur.h"

struct Monstre {
    int vie;
    int attaqueMin;
    int attaqueMax;
    int defense;
    char sprite[10][10];
};


void afficherMonstre(struct Monstre monstre);
void genererSprite(struct Monstre *monstre, int typeSprite);

#endif
