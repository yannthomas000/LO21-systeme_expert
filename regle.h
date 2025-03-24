//
// Created by yannt on 04/11/2023.
//

#ifndef SYSTEMEEXPERT_REGLE_H
#define SYSTEMEEXPERT_REGLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure pour représenter une proposition
typedef struct Proposition {
    char valeur;  // La valeur de la proposition
    struct Proposition* suivante;  // Pointeur vers la proposition suivante dans la prémisse
} Proposition;

// Structure pour représenter une règle
typedef struct Regle {
    Proposition* premisse;  // Liste de propositions dans la prémisse
    char conclusion;  // La conclusion de la règle
    struct Regle* suivante;  // Pointeur vers la règle suivante
} Regle;

// Structure pour représenter une base de connaissance
typedef struct BC {
    Regle* regle;  // Liste de règles
} BC;

// Structure pour représenter une base de faits
typedef struct BaseFaits {
    Proposition* propositions;  // Liste de propositions dans la base de faits
} BaseFaits;

Regle* creerRegle();
void ajouterProposition(Regle* regle, char valeur);
void supprimerProposition(Proposition** premisse, char valeur);
void creerConclusion(Regle* regle, char valeur);
char conclusionRegle(Regle* regle);
char tetePremisse(Regle* regle);
bool propositionDansPremisse(Proposition* premisse, char valeur);
bool premisseEstVide(Regle* regle);
Regle* creerEtAjouterRegle(BC* baseConnaissances, char* propositions, char conclusion);
void afficherRegle(Regle* regle);


BC* creerBaseConnaissances();
void ajouterRegle(BC* base, Regle* regle);
Regle* teteBaseConnaissances(BC* base);


BaseFaits creerBaseFaitsVide();
void ajouterFait(BaseFaits* baseFaits, char valeur);
bool faitExiste(BaseFaits* baseFaits, char valeur);
void afficherBaseFaits(BaseFaits* baseFaits);


void libererBaseConnaissances(BC* baseConnaissances);
void libererBaseFaits(BaseFaits* baseFaits);
void libererProposition(Proposition* proposition);
void libererRegle(Regle* regle);

#endif //SYSTEMEEXPERT_REGLE_H
