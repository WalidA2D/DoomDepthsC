//
// Created by yweng on 16/10/2023.
//
#include "carte.h"
#include "../Joueur/joueur.h"
#include <string.h>
#include "../combat/combat.h"
int joueurX ;
int joueurY;
Map carteActuel;
void afficherMap(Map map){
    for(int i = 0; i<map.xMax; i++){
        for(int j =0; j< map.yMax; j++){
            if(joueurX==i && joueurY==j){
                printf("J  ");
            }else{
                printf( "%d  ", map.carte[i][j]);
            }

        }
        printf("\n");
    }
}
int mouvementPossible( int newX, int newY){
    if(newY>carteActuel.yMax||newX>carteActuel.xMax||newY<0||newX<0||carteActuel.carte[newX][newY]==1) {
        return 0;
    }else{
        return 1;
    }
}
void bouger(char input, Joueur *heros){
    if(input == 'q'&&mouvementPossible(joueurX,(joueurY)-1))
    {
        joueurY-=1;
        evenementMap(heros);

    }else if(input == 'd'&&mouvementPossible(joueurX,(joueurY)+1))
    {
        joueurY+=1;
        evenementMap(heros);

    }else if(input == 'z'&&mouvementPossible(joueurX-1,joueurY))
    {
        joueurX-=1;
        evenementMap(heros);

    }else if(input == 's'&&mouvementPossible(joueurX+1,joueurY))
    {
        joueurX+=1;
        evenementMap(heros);
    }

}

void changerCarte(char input){
    if(input - 48 == 0){
        carteActuel=maison;
        joueurX=4;
        joueurY=2;
    }else if(input - 48 == 1){
        carteActuel=zone1;
        joueurX=0;
        joueurY=3;
    }else if(input -48 ==2){
        carteActuel=zone2;
        joueurX=0;
        joueurY=3;
    }
}

void evenementMap(Joueur * heros){
    if(carteActuel.carte[joueurX][joueurY]==2){
        printf("Vous etes soigne\n");
        heros->vie=100;
    }else if(carteActuel.carte[joueurX][joueurY]==3) {
        if (strcmp(carteActuel.nom, "maison") == 0) {
            changerCarte('1');
        } else if (strcmp(carteActuel.nom, "zone de depart") == 0 && joueurX == 0) {
            changerCarte('0');
        } else if (strcmp(carteActuel.nom, "zone de depart") == 0 && joueurX != 0) {
            changerCarte('2');

        } else if (strcmp(carteActuel.nom, "chateau mortel") == 0) {
            changerCarte('1');
            joueurX=10;
        }
    }else if(carteActuel.carte[joueurX][joueurY]==4) {
        if (strcmp(carteActuel.nom, "zone de depart") == 0) {
            combatBoss(heros, BossZone1);
            carteActuel.carte[joueurX][joueurY]=0;
        } else if (strcmp(carteActuel.nom, "chateau mortel") == 0) {
            combatBoss(heros, BossZone2);
            carteActuel.carte[joueurX][joueurY]=0;
        }
    }else if(carteActuel.carte[joueurX][joueurY]==9){
        combatBoss(heros, BossFinal);
    }else if(carteActuel.carte[joueurX][joueurY]==5){
        int result =rand()%10;
        if(result<3){
            combat(heros);

        }
    }
}
