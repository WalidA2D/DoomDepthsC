#include <stdio.h>
#include <stdlib.h>
#include "../Monstre/monstre.h"
#include "joueur.h"

// Fonction pour afficher les statistiques du joueur
void afficherJoueur(Joueur joueur) {
    printf("Points de vie du joueur: %d\n", joueur.vie);
    printf("Attaques par tour: %d\n", joueur.attaquesParTour);
    printf("Puissance Min: %d\n", joueur.attaqueMin);
    printf("Puissance Max: %d\n", joueur.attaqueMax);
    printf("La resistance de l'armure: %d\n", joueur.defense);
    printf("\n");
}

// Fonction pour attaquer un monstre


