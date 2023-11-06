//
// Created by yweng on 17/10/2023.
//

#ifndef DOOMDEPTHSC_LISTECARTE_H
#define DOOMDEPTHSC_LISTECARTE_H
#include "carte.h"
//0 pour rien, 1 pour mur, 2 pour soin, 3 pour teleport, 4 combat, 5 combat aléatoirement(haute herbe), 9 combat final

Map maison ={
        .carte= {
                {1,1,1,1,1},
                {1,0,0,0,1},
                {1,0,2,0,1},
                {1,0,0,0,1},
                {1,1,3,1,1}
        },
        .xMax=5,
        .yMax=5,
        .nom="maison"

};
Map zone1 ={
        .carte= {
                {0,0,0,3,0,0,0},
                {5,5,5,5,5,5,5},
                {5,5,5,5,5,5,5},
                {5,5,5,5,5,5,5},
                {5,5,5,5,5,5,5},
                {5,5,5,5,5,5,5},
                {5,5,5,5,5,5,5},
                {5,5,5,5,5,5,5},
                {0,0,0,0,0,0,0},
                {0,0,1,4,1,0,0},
                {0,0,1,3,1,0,0},
        },
        .xMax=11,
        .yMax=7,
        .nom="zone de depart"

};

Map zone2 ={
        .carte= {
                {0,0,0,3,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,2,0,0,0},
                {0,0,0,0,0,0,0},
                {1,1,1,4,1,1,1},
                {1,0,0,0,0,0,1},
                {1,0,0,0,0,0,1},
                {1,0,0,0,0,0,1},
                {1,0,0,0,0,0,1},
                {1,0,0,9,0,0,1},
                {1,1,1,1,1,1,1},
        },
        .xMax=11,
        .yMax=7,
        .nom="chateau mortel"

};

#endif //DOOMDEPTHSC_LISTECARTE_H
