//
// Created by yweng on 31/10/2023.
//

#ifndef DOOMDEPTHSC_LISTEBOSS_H
#define DOOMDEPTHSC_LISTEBOSS_H
#include "monstre.h"
#include <stdio.h>
#include <stdlib.h>

struct Monstre BossZone1={
        .attaqueMin=100,
        .attaqueMax=160,
        .defense=40,
        .vie=200,
        .sprite={
                {'_','_','_','_','_','_','_','_','_','_'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'_','_','_','_','_','_','_','_','_','_'},
        }
};


struct Monstre BossZone2={
        .attaqueMin=200,
        .attaqueMax=320,
        .defense=80,
        .vie=400,
        .sprite={
                {'_','_','_','_','_','_','_','_','_','_'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'_','_','_','_','_','_','_','_','_','_'},
        }
};

struct Monstre BossFinal={
        .attaqueMin=800,
        .attaqueMax=1280,
        .defense=320,
        .vie=1600,
        .sprite={
                {'_','_','_','_','_','_','_','_','_','_'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                {'_','_','_','_','_','_','_','_','_','_'},
        }
};


#endif //DOOMDEPTHSC_LISTEBOSS_H