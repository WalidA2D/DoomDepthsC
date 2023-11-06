//
// Created by yweng on 02/10/2023.
//

#ifndef DOOMDEPTHSC_ARME_H
#define DOOMDEPTHSC_ARME_H

#include "../Joueur/joueur.h"
typedef struct{
    char* id;
    char* nom;
    int nbTour;
    int attaqueMin;
    int attaqueMax;
    int rarete;
}arme;
void ajouterArme(arme arme, int* nbArme,Joueur *joueur);
void detruireArme(int* nbArme, int indiceArme);
void afficherListeArme(int nbArme, Joueur *joueur);
void afficherDetailArme( arme arme, int indiceArme, Joueur *joueur);
void equiperArme(arme arme, int *nbArme, short *equipeArme, Joueur *joueur);
void desequiperArme(int *nbArme, short *equipeArme, Joueur *joueur);
void afficherArmeEquipe();
arme donnerArme();

extern arme listeArme[4];
extern int nbArme;
extern arme armeEquipe;
extern short equipeArme;


extern int nbArmeR1;

extern int nbArmeR2;

extern int nbArmeR3;
extern arme *armes[3];


#endif //DOOMDEPTHSC_ARME_H
