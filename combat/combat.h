//
// Created by yweng on 31/10/2023.
//

#ifndef DOOMDEPTHSC_COMBAT_H
#define DOOMDEPTHSC_COMBAT_H
#include <stdio.h>
#include <stdlib.h>
#include "../Joueur/joueur.h"
#include "../Monstre/monstre.h"

extern struct Monstre BossZone1;
extern struct Monstre BossZone2;
extern struct Monstre BossFinal;

void genererNouveauxMonstres(struct Monstre *monstres, int nombreDeMonstres);
void attaquerMonstres(struct Monstre *monstres, int nombreDeMonstres, Joueur *joueur);
void attaquerMonstre(struct Monstre *monstre, int attaque, int indiceMonstre);
int tousLesMonstresSontMorts(struct Monstre *monstres, int nombreDeMonstres);
void recevoirRecompense(Joueur *joueur);
void combat(Joueur* heros);
void combatBoss(Joueur* heros, struct Monstre boss);


#endif //DOOMDEPTHSC_COMBAT_H
