//
// Created by yweng on 02/10/2023.
//

#ifndef DOOMDEPTHSC_ARMURE_H
#define DOOMDEPTHSC_ARMURE_H

#include "../Joueur/joueur.h"
typedef struct{
    char* id;
    char *nom;
    int defense;
    int rarete;
}armure;
void ajouterArmure(armure armure, int* nbArmure,Joueur* joueur);
void detruireArmure(int* nbArmure, int indice);
void afficherListeArmure(int nbArmure, Joueur *joueur);
void afficherDetailArmure(armure armure,int indice, Joueur* joueur);
void equiperArmure(armure armure, int *nbArmure, short *equipeArmure, Joueur *joueur);
void desequiperArmure(int *nbArmure, short *equipeArmure, Joueur* joueur);
void afficherArmureEquipe();
armure donnerArmure();

extern armure listeArmure[4];
extern int nbArmure;
extern armure armureEquipe;
extern short equipeArmure;

extern int nbArmureR1;

extern int nbArmureR2;

extern int nbArmureR3;
extern armure *armures[3];
#endif //DOOMDEPTHSC_ARMURE_H
