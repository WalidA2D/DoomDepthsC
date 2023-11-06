//
// Created by yweng on 31/10/2023.
//
#include "../Joueur/joueur.h"
#include "../Monstre/monstre.h"
#include "../equipement/arme.h"
#include "../equipement/armure.h"
#include <stdio.h>
#include <stdlib.h>

void genererNouveauxMonstres(struct Monstre *monstres, int nombreDeMonstres) {
    int bonusVie = 100;
    int bonusAttaqueMin = 20;
    int bonusAttaqueMax = 50;
    int bonusDefense = 25;

    for (int i = 0; i < nombreDeMonstres; i++) {
        monstres[i].vie += bonusVie;
        monstres[i].attaqueMin += bonusAttaqueMin;
        monstres[i].attaqueMax += bonusAttaqueMax;
        monstres[i].defense += bonusDefense;

        int typeSpriteAleatoire = rand() % 4;

        genererSprite(&monstres[i], typeSpriteAleatoire);
    }
}

// Fonction pour gérer l'attaque des monstres sur le joueur
void attaquerMonstres(struct Monstre *monstres, int nombreDeMonstres,  Joueur *joueur) {
    for (int i = 0; i < nombreDeMonstres; i++) {
        if (monstres[i].vie > 0) {
            int degatsMonstre = rand() % (monstres[i].attaqueMax - monstres[i].attaqueMin + 1) + monstres[i].attaqueMin;
            int degatsSubis = degatsMonstre - (joueur->defense);
            if (degatsSubis > 0) {
                joueur->vie -= degatsSubis;
                printf("Le monstre %d vous a inflige %d degats.\n", i + 1, degatsSubis);
            } else {
                printf("Le monstre %d a attaque, mais votre defense est trop elevee, l'attaque est inefficace.\n", i + 1);
            }
        }
    }
}
void attaquerMonstre(struct Monstre *monstre, int attaque, int indiceMonstre) {
    int degats = attaque - monstre->defense;
    if (degats > 0) {
        monstre->vie -= degats;
        printf("Le monstre %d a subi %d degats. Points de vie restants : %d\n",indiceMonstre, degats, monstre->vie);
    } else {
        printf("Le monstre est trop fort, votre attaque est inefficace.\n");
    }
}

// Fonction pour vérifier si tous les monstres sont morts
int tousLesMonstresSontMorts(struct Monstre *monstres, int nombreDeMonstres) {
    for (int i = 0; i < nombreDeMonstres; i++) {
        if (monstres[i].vie > 0) {
            return 0;
        }
    }
    return 1;
}

void recevoirRecompense(Joueur *joueur){

    int type=rand() % 2;
    if(type==0){
        arme armeRecu = donnerArme();
        printf("vous avez recu %s\n", armeRecu.nom);
        ajouterArme(armeRecu, &nbArme, joueur);
    }else{
        armure armureRecu = donnerArmure();
        printf("vous avez recu %s\n", armureRecu.nom);
        ajouterArmure(armureRecu, &nbArmure, joueur);
    }

}

void combat(Joueur *heros){
    // Générez des monstres aléatoire
    int nombreDeMonstres = rand() % 3+2;

    struct Monstre monstres[nombreDeMonstres];

    // Générez aléatoirement des statistiques et un type de sprite pour chaque monstre
    for (int i = 0; i < nombreDeMonstres; i++) {
        monstres[i].vie = rand() % 100 + 50; // Vie entre 50 et 149
        monstres[i].attaqueMin = rand() % 10 + 5; // Attaque minimale entre 5 et 14
        monstres[i].attaqueMax = monstres[i].attaqueMin + rand() % 10; // Attaque maximale entre attaqueMin et attaqueMin + 9
        monstres[i].defense = rand() % 20 + 10; // Défense entre 10 et 29

        int typeSpriteAleatoire = rand() % 4;

        // Générez le sprite pour le monstre en utilisant la fonction genererSprite
        genererSprite(&monstres[i], typeSpriteAleatoire);

    }

    //Affichez les informations des monstres
    printf("Monstres generes :\n\n");
    for (int i = 0; i < nombreDeMonstres; i++) {
        printf("Monstre %d :\n", i + 1);
        afficherMonstre(monstres[i]);
    }


    while (heros->vie > 0) {
        if (tousLesMonstresSontMorts(monstres, nombreDeMonstres)) {
            recevoirRecompense(heros);
            break;
        }
        afficherJoueur(*heros);

        int attaquesRestantes = heros->attaquesParTour;

        while (attaquesRestantes > 0) {
            printf("Attaques restantes ce tour : %d\n", attaquesRestantes);

            if (tousLesMonstresSontMorts(monstres, nombreDeMonstres)) {
                printf("Tous les monstres sont morts !\n");

                break;
            }

            printf("Choisissez un monstre a attaquer (de 1 à %d) \n0 pour terminer le tour\nw pour afficher les armes possedees\na pour afficher les armures possedee\nj pour afficher les stats du joueur\n ", nombreDeMonstres);
            char choixMonstre;
            fflush(stdin);
            scanf("%c", &choixMonstre);
            if(choixMonstre=='j'){
                afficherJoueur(*heros);
            }else if(choixMonstre=='w') {
                afficherListeArme(nbArme, &heros);
            }else if(choixMonstre=='a') {
                afficherListeArmure(nbArmure, &heros);
            }else if (choixMonstre-48 >= 1 && choixMonstre-48 <= nombreDeMonstres) {
                if (monstres[choixMonstre-48 - 1].vie <= 0) {
                    printf("Le monstre est mort !\n");

                } else {
                    int attaque= heros->attaqueMin+(rand()%(heros->attaqueMax-heros->attaqueMin));
                    attaquerMonstre(&monstres[choixMonstre -48- 1], attaque, choixMonstre-48);
                    attaquesRestantes--;
                }
            } else if (choixMonstre-48 == 0) {
                // Le joueur termine son tour
                printf("Fin du tour du joueur.\n");
                break;
            } else {
                fflush(stdin);
                printf("Choix invalide.\n");
            }
            choixMonstre=' ';

        }


        attaquerMonstres(monstres, nombreDeMonstres, heros);

        // Vérifiez si le joueur est mort
        if (heros->vie <= 0) {
            printf("Le joueur est mort. Fin de la partie.\n");
            break;
        }
    }

}

void combatBoss(Joueur *heros, struct Monstre boss){
    int nombreDeMonstres = 1;

    struct Monstre monstres[nombreDeMonstres];
    monstres[0]=boss;


    //Affichez les informations des monstres
    printf("Le boss :\n\n");
    for (int i = 0; i < nombreDeMonstres; i++) {
        printf("Monstre %d :\n", i + 1);
        afficherMonstre(monstres[i]);
    }

    while (heros->vie > 0) {
        if (tousLesMonstresSontMorts(monstres, nombreDeMonstres)) {
            recevoirRecompense(heros);
            break;
        }
        afficherJoueur(*heros);

        int attaquesRestantes = heros->attaquesParTour;

        while (attaquesRestantes > 0) {
            printf("Attaques restantes ce tour : %d\n", attaquesRestantes);

            if (tousLesMonstresSontMorts(monstres, nombreDeMonstres)) {
                printf("Tous les monstres sont morts !\n");

                break;
            }

            printf("taper 1 pour attaquer le boss \n0 pour terminer le tour\nw pour afficher les armes possedees\na pour afficher les armures possedee\nj pour afficher les stats du joueur\n ", nombreDeMonstres);
            char choixMonstre;
            fflush(stdin);
            scanf("%c", &choixMonstre);
            if(choixMonstre=='j'){
                afficherJoueur(*heros);
            }else if(choixMonstre=='w') {
                afficherListeArme(nbArme, heros);
            }else if(choixMonstre=='a') {
                afficherListeArmure(nbArmure, heros);
            }else if (choixMonstre-48 >= 1 && choixMonstre-48 <= nombreDeMonstres) {
                if (monstres[choixMonstre-48 - 1].vie <= 0) {
                    printf("Le monstre est mort !\n");

                } else {
                    int attaque= heros->attaqueMin+(rand()%(heros->attaqueMax-heros->attaqueMin));
                    attaquerMonstre(&monstres[choixMonstre -48- 1], attaque, choixMonstre-48);
                    attaquesRestantes--;
                }
            } else if (choixMonstre-48 == 0) {
                // Le joueur termine son tour
                printf("Fin du tour du joueur.\n");
                break;
            } else {
                fflush(stdin);
                printf("Choix invalide.\n");
            }
            choixMonstre=' ';

        }


        attaquerMonstres(monstres, nombreDeMonstres, heros);

        // Vérifiez si le joueur est mort
        if (heros->vie <= 0) {
            printf("Le joueur est mort. Fin de la partie.\n");
            break;
        }
    }

}