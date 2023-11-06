//
// Created by yweng on 03/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "armure.h"
#include <time.h>


int nbArmureR1=1;
int nbArmureR2=1;
int nbArmureR3=1;
armure *armures[3];
armure rien={
        .id="b0",
        .nom="rien",
        .defense=0,
        .rarete=3
};
armure listeArmure[4];
int nbArmure = 0;
armure armureEquipe;
short equipeArmure=0;

void ajouterArmure(armure armure, int* nbArmure,Joueur *joueur){
    if(*nbArmure==4){

        char choix;
        fflush(stdin);

        afficherListeArmure(*nbArmure, joueur );
        do {
            fflush(stdin);
            printf("Veuillez entrer le numero de l\'armure a echange avec %s sinon taper n pour jeter l\'armure\n", armure.nom);

            scanf("%c", &choix);
        }while((choix-48>4 || choix-48<0)&&choix!='n');
        if(choix=='n'){
            return;
        }else {
            listeArmure[choix - 48] = armure;
        }
    }else{
        listeArmure[*nbArmure]=armure;
        *nbArmure+=1;

    }
}
void detruireArmure(int *nbArmure, int indice){

        *nbArmure-=1;
        for(int i =indice; i<*nbArmure; i++){
            listeArmure[i]=listeArmure[i+1];

        }


}

void afficherListeArmure(int nbArmure, Joueur *joueur){
    for(int i = 0; i<nbArmure; i++) {
        printf("armure numero %d : %s\n", i, listeArmure[i].nom);
    }

    char choix;
    fflush(stdin);
    do{
        printf("Ecrivez le numero de l\'armure pour voir ces details sinon taper n pour sortir\n");

        scanf("%c", &choix);
    }while((choix-48<0 || choix-48>nbArmure)&& choix!='n');
    if(choix =='n'){
        return;
    }else{
        afficherDetailArmure(listeArmure[choix-48], choix-48, joueur);
    }
}


void afficherDetailArmure(armure armure, int indice, Joueur *joueur){
    printf("nom : %s\n", armure.nom);
    printf("defense: %d\n", armure.defense);
    printf("rarete : %d\n", armure.rarete);
    fflush(stdin);
    char choix;
    do{
        printf("equiper l\'armure ? taper e\ndetruire l\'armure ? taper d\nSortir ? taper n\n");
        scanf("%c", &choix);
    }while(choix!='e'&& choix!='d' && choix!='n');
    if(choix=='e'){
        equiperArmure(armure, &nbArmure,  &equipeArmure, joueur);
        detruireArmure(&nbArmure, indice);
    }else if(choix=='d'){
        detruireArmure(&nbArmure, indice);
    }else{
        return;
    }
}

void desequiperArmure(int *nbArmure, short * equipeArmure, Joueur *joueur){
    if(*equipeArmure==0){
        printf("pas d\'armure a desequipe");
    }else{
        if(*nbArmure==4){
            printf("pas de place dans l\'inventaire");
        }else {
            listeArmure[*nbArmure]=armureEquipe;
            *nbArmure+=1;

            joueur->defense-=armureEquipe.defense;

            armureEquipe=rien;
            *equipeArmure=0;
        }
    }
}
void equiperArmure(armure armure, int *nbArmure, short * equipeArmure, Joueur *joueur){
    if(*equipeArmure==0){
        armureEquipe = armure;
        *equipeArmure=1;
    }else{
        char choix;
        do {
            printf("retirer l\'armure equipe pour equipe %s ? y/n", armure.nom);
            scanf("%c", &choix);
        }while(choix!='y'&&choix!='n');
        if(choix=='y'){
            desequiperArmure(nbArmure, equipeArmure, joueur);
            joueur->defense+=armure.defense;
            armureEquipe =armure;
            *nbArmure-=1;

        }else {
            return;
        }
    }
}

void afficherArmureEquipe(){
    if(equipeArmure==0){
        printf("nom : %s\n", rien.nom);
        printf("defense : %d\n", rien.defense);

        printf("rarete : %d\n", rien.rarete);
    }else{
        printf("nom : %s\n", armureEquipe.nom);

        printf("defense : %d\n", armureEquipe.defense);
        printf("rarete : %d\n", armureEquipe.rarete);
    }
}

armure donnerArmure(){
    srand(time(NULL));
    int rareteArmure=rand() % 10;
    armure armureADonner;
    if(rareteArmure<6){
        int indiceArme=rand() % nbArmureR3;
        armureADonner=armures[0][indiceArme];
    }else if(rareteArmure<9){
        int indiceArme=rand() % nbArmureR2;
        armureADonner=armures[1][indiceArme];
    }else{
        int indiceArme=rand() % nbArmureR1;
        armureADonner=armures[2][indiceArme];
    }
    return armureADonner;
}