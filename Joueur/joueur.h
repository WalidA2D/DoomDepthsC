#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct  {
    int vie;
    int attaquesParTour;
    int attaqueMin;
    int attaqueMax;
    int defense;
}Joueur;


struct Monstre;

void afficherJoueur(Joueur joueur);

#endif
