#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
// Fonction pour sauvegarder la partie
void sauvegarderPartie(GameState gameState) {
    FILE *fichier = fopen("sauvegarde.dat", "wb");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }

    fwrite(&gameState.heros, sizeof(Joueur), 1, fichier);

    fwrite(&gameState.carte, sizeof(Map), 1, fichier);
    fwrite(&joueurX, sizeof(int), 1, fichier);
    fwrite(&joueurY, sizeof(int), 1, fichier);

    fclose(fichier);
}


// Fonction pour charger la partie
int chargerPartie(GameState *gameState) {
    FILE *fichier = fopen("sauvegarde.dat", "rb");
    if (fichier == NULL) {
        printf("Aucun fichier de sauvegarde trouvé.\n");
        return 0;  // Échec de chargement
    }

    if (fread(&gameState->heros, sizeof(Joueur), 1, fichier) != 1) {
        printf("Erreur de lecture des données du joueur.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->carte, sizeof(Map), 1, fichier) != 1) {
        printf("Erreur de lecture des données de la carte.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&joueurX, sizeof(int), 1, fichier) != 1 ||
        fread(&joueurY, sizeof(int), 1, fichier) != 1) {
        printf("Erreur de lecture de la position du joueur.\n");
        fclose(fichier);
        return 0;  // Échec de chargement
    }

    fclose(fichier);

    return 1;
}


