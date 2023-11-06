#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "../Joueur/joueur.h"
#include "../carte/carte.h"

typedef struct {
    Joueur heros;
    Map carte;
    int joueurX;
    int joueurY;
} GameState;


void sauvegarderPartie(GameState gameState);
int chargerPartie(GameState *gameState);

#endif // SAUVEGARDE_H
