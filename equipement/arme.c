//
// Created by yweng on 02/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arme.h"


int nbArmeR1=1;
int nbArmeR2=2;
int nbArmeR3=3;
arme *armes[3];
arme poing={
        .id="a0",
        .nom="poing",
        .nbTour=3,
        .attaqueMin=0,
        .attaqueMax=0,
        .rarete=3
};



arme listeArme[4];
int nbArme=0;
arme armeEquipe;
short equipeArme=0;


void ajouterArme(arme arme, int* nbArme,Joueur *joueur){
    if(*nbArme==4){

        char choix;
        fflush(stdin);

        afficherListeArme(*nbArme, joueur);
        do {
            printf("Veuillez entrer le numero de l\'arme a echange avec %s sinon taper n pour sortir\n", arme.nom);
            scanf("%c", &choix);
        }while((choix-48>4 || choix-48<0)&&choix!='n');
        if(choix=='n'){
            printf("jeter %s", arme.nom);
            return;
        }else {
            listeArme[choix - 48] = arme;
        }
    }else{
        listeArme[*nbArme]=arme;
        *nbArme+=1;
    }
}
void detruireArme(int *nbArme, int indiceArme){
    *nbArme-=1;
    printf("vous avez detruit %s ", listeArme[indiceArme].nom);
    for(int i =indiceArme; i<*nbArme; i++){
        listeArme[i]=listeArme[i+1];
    }

}

void afficherListeArme( int nbArme, Joueur* joueur){
    for(int i = 0; i<nbArme; i++){
        printf("arme numero %d : %s\n",i,listeArme[i].nom);

    }
    fflush(stdin);
    char choix;
    do{
        printf("Ecrivez le numero de l'arme pour voir ces details sinon taper n pour sortir\n");
        scanf("%c", &choix);
    }while((choix-48<0 || choix-48>nbArme)&& choix!='n');
    if(choix =='n'){
        return;
    }else{
        afficherDetailArme(listeArme[choix-48], choix-48, joueur);
    }
}

void afficherDetailArme( arme arme, int indice, Joueur *joueur){
    printf("nom : %s\n", arme.nom);
    printf("attaque min : %d\n", arme.attaqueMin);
    printf("attaque max : %d\n", arme.attaqueMax);
    printf("nombre de tour : %d\n", arme.nbTour);
    printf("rarete : %d\n", arme.rarete);
    fflush(stdin);
    char choix;
    do{
        fflush(stdin);
        printf("equiper l\'arme ? taper e\ndetruire l\'arme ? taper d\nSortir ? taper n\n");
        scanf("%c", &choix);
    }while(choix!='e'&& choix!='d' && choix!='n');
    if(choix=='e'){
        equiperArme( arme, &nbArme,  &equipeArme, joueur);
        detruireArme(&nbArme, indice);
    }else if(choix=='d'){
        detruireArme(&nbArme, indice);
    }else{
        return;
    }


}
void desequiperArme(int *nbArme, short * equipeArme, Joueur *joueur){
    if(*equipeArme==0){
        printf("pas d\'arme a desequipe");
    }else{
        if(*nbArme==4){
            printf("pas de place dans l\'inventaire");
        }else {
            listeArme[*nbArme]=armeEquipe;
            *nbArme+=1;

            joueur->attaqueMin-=armeEquipe.attaqueMin;
            joueur->attaqueMax-=armeEquipe.attaqueMax;
            joueur->attaquesParTour-=armeEquipe.nbTour;
            armeEquipe=poing;
            *equipeArme=0;
        }
    }
}
void equiperArme(arme arme, int *nbArme, short * equipeArme, Joueur *joueur){
    if(*equipeArme==0){
        armeEquipe = arme;
        joueur->attaqueMin+=arme.attaqueMin;
        joueur->attaqueMax+=arme.attaqueMax;
        joueur->attaquesParTour+=arme.nbTour;
        *equipeArme=1;

    }else{
        char choix;
        do {
            printf("retirer l\'arme equipe pour equipe %s ? y/n", arme.nom);
            scanf("%c", &choix);
        }while(choix!='y'&&choix!='n');
        if(choix=='y'){
            desequiperArme(nbArme, equipeArme,joueur);
            armeEquipe =arme;
            *nbArme-=1;

        }else {
            return;
        }
    }
}

void afficherArmeEquipe(){
    if(equipeArme==0){
        printf("nom : %s\n", poing.nom);
        printf("attaque min : %d\n", poing.attaqueMin);
        printf("attaque max : %d\n", poing.attaqueMax);
        printf("nombre de tour : %d\n", poing.nbTour);
        printf("rarete : %d\n", poing.rarete);
    }else{
        printf("nom : %s\n", armeEquipe.nom);
        printf("attaque min : %d\n", armeEquipe.attaqueMin);
        printf("attaque max : %d\n", armeEquipe.attaqueMax);
        printf("nombre de tour : %d\n", armeEquipe.nbTour);
        printf("rarete : %d\n", armeEquipe.rarete);
    }
}




arme donnerArme(){

    int rareteArme=rand() % 10;
    arme armeADonner;
    if(rareteArme<6){
        int indiceArme=rand() % nbArmeR3;
        armeADonner=armes[0][indiceArme];
    }else if(rareteArme<9){
        int indiceArme=rand() % nbArmeR2;
        armeADonner=armes[1][indiceArme];
    }else{
        int indiceArme=rand() % nbArmeR1;
        armeADonner=armes[2][indiceArme];
    }
    return armeADonner;
}

