#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Monstre/monstre.h"
#include "Joueur/joueur.h"
#include "equipement/listeArme.h"
#include "equipement/listeArmure.h"
#include "carte/listeCarte.h"
#include "combat/combat.h"
#include "Monstre/listeBoss.h"
#include "sauvegarde/sauvegarde.h"

int main() {
    srand(time(NULL));

    char choix;
    printf("Bienvenue dans DoomDepthsC!\n");
    printf("1. Nouvelle partie\n");
    printf("2. Charger une partie\n");
    do {
        scanf(" %c", &choix);
    } while (choix != '1' && choix != '2');

    Joueur heros;
    if (choix == '1') {
        // Initialiser un nouveau jeu
        heros = (Joueur){
                .vie = 100,
                .attaquesParTour = 2,
                .attaqueMin = 50,
                .attaqueMax = 80,
                .defense = 20
        };
        arme armeR3[] = {dague, baton, marteau};
        arme armeR2[] = {epee, hache};
        arme armeR1[] = {excalibur};
        armes[0] = armeR3;
        armes[1] = armeR2;
        armes[2] = armeR1;

        armure armureR3[] = {cuir};
        armure armureR2[] = {fer};
        armure armureR1[] = {adamantium};
        armures[0] = armureR3;
        armures[1] = armureR2;
        armures[2] = armureR1;

        changerCarte('0');
        joueurX = 2;
        joueurY = 2;
    } else if (choix == '2') {
        // Charger une partie sauvegardée
        GameState gameState;
        gameState.heros = heros;
        gameState.carte = carteActuel;


        if (chargerPartie(&gameState) == 0) {
            printf("Impossible de charger la partie. Nouvelle partie en cours.\n");
            heros = (Joueur){
                    .vie = 100,
                    .attaquesParTour = 2,
                    .attaqueMin = 50,
                    .attaqueMax = 80,
                    .defense = 20
            };
            arme armeR3[] = {dague, baton, marteau};
            arme armeR2[] = {epee, hache};
            arme armeR1[] = {excalibur};
            armes[0] = armeR3;
            armes[1] = armeR2;
            armes[2] = armeR1;

            armure armureR3[] = {cuir};
            armure armureR2[] = {fer};
            armure armureR1[] = {adamantium};
            armures[0] = armureR3;
            armures[1] = armureR2;
            armures[2] = armureR1;

            changerCarte('0');
            joueurX = 2;
            joueurY = 2;
        } else {
            heros = gameState.heros;
            carteActuel = gameState.carte;



            // Remplissez gameState avec d'autres données de la partie, si nécessaire
        }
    }

    char input = ' ';
    while (input != 'p') {
        afficherMap(carteActuel);
        fflush(stdin);
        scanf(" %c", &input);
        if (input == '!') {
            GameState gameStateToSave;
            gameStateToSave.heros = heros;
            gameStateToSave.carte = carteActuel;
            // Remplissez gameStateToSave avec d'autres données de la partie, si nécessaire



            sauvegarderPartie(gameStateToSave);
            printf("Partie sauvegardée.\n");
        } else {
            bouger(input, &heros);
        }
        fflush(stdout);
        if (heros.vie <= 0) {
            break;
        }
    }


    return 0;
}
