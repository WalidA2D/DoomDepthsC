#include <stdio.h>

struct Monstre {
    int vie;
    int attaqueMin;
    int attaqueMax;
    int defense;
    char sprite[10][10];
};

// Fonction pour afficher un monstre avec son sprite
void afficherMonstre(struct Monstre monstre) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", monstre.sprite[i][j]);
        }
        printf("\n");
    }
    printf("Vie: %d\n", monstre.vie);
    printf("Attaque Min: %d\n", monstre.attaqueMin);
    printf("Attaque Max: %d\n", monstre.attaqueMax);
    printf("Defense: %d\n", monstre.defense);
    printf("\n");
}

// Fonction pour générer le sprite en fonction du type de monstre
void genererSprite(struct Monstre *monstre, int typeSprite) {

    char spriteType1[10][10] = {
            {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', '*', '*', '*', ' ', '*', ' ', ' ', ' ', ' '},
            {'*', '*', 'M', '*', '*', '*', ' ', ' ', ' ', ' '},
            {' ', '*', '*', '*', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    char spriteType2[10][10] = {
            {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', '*', 'M', '*', ' ', '*', ' ', ' ', ' ', ' '},
            {'*', '*', 'M', '*', '*', '*', ' ', ' ', ' ', ' '},
            {' ', '*', 'M', '*', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    char spriteType3[10][10] = {
            {' ', 'M', 'M', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
            {'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M'},
            {'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M'},
            {'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M'},
            {' ', 'M', 'M', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', 'M', 'M', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', 'M', 'M', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', 'M', 'M', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    char spriteType4[10][10] = {
            {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', '*', '*', '*', ' ', '*', ' ', ' ', ' ', ' '},
            {'*', 'M', '*', 'M', '*', '*', ' ', ' ', ' ', ' '},
            {' ', '*', '*', '*', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            switch (typeSprite) {
                case 0:
                    monstre->sprite[row][col] = spriteType1[row][col];
                    break;
                case 1:
                    monstre->sprite[row][col] = spriteType2[row][col];
                    break;
                case 2:
                    monstre->sprite[row][col] = spriteType3[row][col];
                    break;
                case 3:
                    monstre->sprite[row][col] = spriteType4[row][col];
                    break;
                default:
                    break;
            }
        }
    }
}

