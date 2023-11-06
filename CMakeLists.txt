cmake_minimum_required(VERSION 3.26)
project(DoomDepthsC C)

set(CMAKE_C_STANDARD 11)

add_executable(DoomDepthsC main.c
        Monstre/generation.c
        Monstre/monstre.h
        Joueur/joueur.c
        Joueur/joueur.h
        equipement/arme.c
        equipement/arme.h
        equipement/armure.h
        equipement/listeArmure.h
        equipement/armure.c
        equipement/listeArme.h
        carte/carte.h
        carte/carte.c
        carte/listeCarte.h
        combat/combat.h
        combat/combat.c
        Monstre/listeBoss.h
        sauvegarde/sauvegarde.h
        sauvegarde/sauvegarde.c
)
