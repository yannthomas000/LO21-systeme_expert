#include <stdio.h>
#include <stdbool.h>
#include "regle.h"

void moteurInference(BC* baseConnaissances, BaseFaits* baseFaits);

int main() {
    // Créer une base de connaissances et ajouter des règles
    BC* baseConnaissances = creerBaseConnaissances();


    //JEUX D'ESSAIS

    // Premier jeu d'essais
    Regle* regle1 = creerEtAjouterRegle(baseConnaissances, "AB", 'C');
    afficherRegle(regle1);

    Regle* regle2 = creerEtAjouterRegle(baseConnaissances, "BCD", 'E');
    afficherRegle(regle2);

    Regle* regle3 = creerEtAjouterRegle(baseConnaissances, "BC", 'F');
    afficherRegle(regle3);

    Regle* regle4 = creerEtAjouterRegle(baseConnaissances, "EF", 'G');
    afficherRegle(regle4);

    Regle* regle5 = creerEtAjouterRegle(baseConnaissances, "ACF", 'I');
    afficherRegle(regle5);


    // Deuxième jeu d'essais
   /* Regle* regle1 = creerEtAjouterRegle(baseConnaissances, "CBD", 'E');
    afficherRegle(regle1);

    Regle* regle2 = creerEtAjouterRegle(baseConnaissances, "AB", 'C');
    afficherRegle(regle2);

    Regle* regle3 = creerEtAjouterRegle(baseConnaissances, "ITE", 'J');
    afficherRegle(regle3);

    Regle* regle4 = creerEtAjouterRegle(baseConnaissances, "DFG", 'A');
    afficherRegle(regle4);

    Regle* regle5 = creerEtAjouterRegle(baseConnaissances, "F", 'D');
    afficherRegle(regle5);

    Regle* regle6 = creerEtAjouterRegle(baseConnaissances, "FDJ", 'R');
    afficherRegle(regle6);

    Regle* regle7 = creerEtAjouterRegle(baseConnaissances, "BD", 'G');
    afficherRegle(regle7);

    Regle* regle8 = creerEtAjouterRegle(baseConnaissances, "CFE", 'X');
    afficherRegle(regle8);

    Regle* regle9 = creerEtAjouterRegle(baseConnaissances, "O", 'T');
    afficherRegle(regle9);*/


    // BASE DE FAITS

    // Initialiser une base de faits avec quelques faits initiaux
    BaseFaits baseFaits = creerBaseFaitsVide();

    //Premier jeu d'essais
    ajouterFait(&baseFaits, 'A');
    ajouterFait(&baseFaits, 'B');

    // Deuxième jeu d'essai
    /*ajouterFait(&baseFaits, 'B');
    ajouterFait(&baseFaits, 'F');*/

    // Afficher la base de faits initiale
    printf("Base de faits initiale :\n");
    afficherBaseFaits(&baseFaits);



    // Appliquer le moteur d'inférence
    moteurInference(baseConnaissances, &baseFaits);

    // Afficher les faits déduits
    printf("\nFaits deduits apres l'inference :\n");
    afficherBaseFaits(&baseFaits);

    // Libérer la mémoire
    libererBaseConnaissances(baseConnaissances);
    libererBaseFaits(&baseFaits);

    return 0;
}


// Moteur d'inférence qui relie la base de connaissance et la base de faits
void moteurInference(BC* baseConnaissances, BaseFaits* baseFaits) {
    bool modification = true;

    while (modification) {
        modification = false;

        // Parcourir les règles dans la base de connaissances
        for (Regle* regle = teteBaseConnaissances(baseConnaissances); regle != NULL; regle = regle->suivante) {

            // Vérifier si la conclusion de la règle est déjà dans la base de faits
            if (faitExiste(baseFaits, conclusionRegle(regle))) {
                continue;
            }

            // Obtenir la tête de la prémisse de la règle
            char tete = tetePremisse(regle);

            // Vérifier si la proposition est dans la base de faits
            if (propositionDansPremisse(baseFaits->propositions, tete)) {
                // Supprimer la proposition de la prémisse de la règle
                supprimerProposition(&regle->premisse, tete);
                modification = true;
            }

            // Si la prémisse est vide, ajouter la conclusion à la base de faits
            if (premisseEstVide(regle)) {
                ajouterFait(baseFaits, conclusionRegle(regle));
                modification = true;
            }
        }
    }
}