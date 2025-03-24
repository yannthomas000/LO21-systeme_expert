//
// Created by yannt on 18/11/2023.
//

#include "regle.h"

// Créer une règle vide
Regle* creerRegle() {
    Regle* nouvelleRegle = (Regle*)malloc(sizeof(Regle));
    if (nouvelleRegle != NULL) {
        nouvelleRegle->suivante = NULL;
        nouvelleRegle->premisse = NULL;
        nouvelleRegle->conclusion = 'o';
    }
    return nouvelleRegle;
}

// Ajouter une proposition à la prémisse d'une règle
void ajouterProposition(Regle* regle, char valeur) {
    Proposition* nouvelleProposition = (Proposition*)malloc(sizeof(Proposition));
    if (nouvelleProposition != NULL) {
        nouvelleProposition->valeur = valeur;
        nouvelleProposition->suivante = NULL;

        if (regle->premisse == NULL) {
            regle->premisse = nouvelleProposition;
        } else {
            // Trouver la dernière proposition dans la prémisse et ajouter la nouvelle proposition
            Proposition* courant = regle->premisse;
            while (courant->suivante != NULL) {
                courant = courant->suivante;
            }
            courant->suivante = nouvelleProposition;
        }
    }
}

// Supprimer une proposition donnée d'une prémisse donnée
void supprimerProposition(Proposition** premisse, char valeur) {
    Proposition* courant = *premisse;
    Proposition* precedente = NULL;

    while (courant != NULL) {
        if (courant->valeur == valeur) {
            if (precedente == NULL) {
                // La proposition à supprimer est en tête de la prémisse
                *premisse = courant->suivante;
            } else {
                // La proposition à supprimer est au milieu ou à la fin de la prémisse
                precedente->suivante = courant->suivante;
            }

            free(courant);
            return;  // La proposition a été trouvée et supprimée, sortie de la fonction
        }

        precedente = courant;
        courant = courant->suivante;
    }
}

// Créer la conclusion d'une règle
void creerConclusion(Regle* regle, char valeur) {
    regle->conclusion = valeur;
}

// Accéder à la conclusion d'une règle
char conclusionRegle(Regle* regle) {
    return regle->conclusion;
}

// Accéder à la proposition se trouvant en tête de la prémisse
char tetePremisse(Regle* regle) {
    if (regle->premisse != NULL) {
        return regle->premisse->valeur;
    }
    return '?';  // Par défaut, retourne ? si la prémisse est vide
}

// Vérifie si une proposition (valeur) donnée est présente dans une prémisse donnée
bool propositionDansPremisse(Proposition* premisse, char valeur) {
    if (premisse == NULL) {
        return false;
    }
    if (premisse->valeur == valeur) {
        return true;
    }
    // Utilisation de la récursivité pour continuer la recherche dans le reste de la prémisse
    return propositionDansPremisse(premisse->suivante, valeur);
}

// Tester si la prémisse d'une règle est vide
bool premisseEstVide(Regle* regle) {
    return regle->premisse == NULL;
}

// Combinaison de fonctions pour remplir plus efficacement la base de connaissance
Regle* creerEtAjouterRegle(BC* baseConnaissances, char* propositions, char conclusion) {
    Regle* nouvelleRegle = creerRegle();

    // Ajouter les propositions à la prémisse de la règle nouvellement crée
    for (int i = 0; propositions[i] != '\0'; ++i) {
        ajouterProposition(nouvelleRegle, propositions[i]);
    }

    // Ajouter la conclusion à la règle
    creerConclusion(nouvelleRegle, conclusion);

    // Ajouter la règle à la base de connaissances
    ajouterRegle(baseConnaissances, nouvelleRegle);

    return nouvelleRegle;
}

// Affiche une règle
void afficherRegle(Regle* regle) {
    if (regle != NULL) {
        Proposition* courante = regle->premisse;

        printf("Premisse : ");
        while (courante != NULL) {
            printf("%c ", courante->valeur);
            courante = courante->suivante;
        }

        printf("=> Conclusion : %c\n", regle->conclusion);
    } else {
        printf("La règle est NULL.\n");
    }
}





// Créer une base vide
BC* creerBaseConnaissances() {
    BC* nouvelleBase = (BC*)malloc(sizeof(BC));
    if (nouvelleBase != NULL) {
        nouvelleBase->regle = NULL;
    }
    return nouvelleBase;
}

// Ajouter une règle à une base
void ajouterRegle(BC* base, Regle* regle) {
    if (base->regle == NULL) {
        base->regle = regle;
    } else {
        // Trouver la dernière règle dans la base et ajouter la nouvelle règle
        Regle* courant = base->regle;
        while (courant->suivante != NULL) {
            courant = courant->suivante;
        }
        courant->suivante = regle;
    }
}

// Accéder à la règle en tête de la base
Regle* teteBaseConnaissances(BC* base) {
    return base->regle;
}




// Crée une base de faits vide
BaseFaits creerBaseFaitsVide() {
    BaseFaits baseFaits;
    baseFaits.propositions = NULL;
    return baseFaits;
}

// Ajoute un fait à une base de faits donnée
void ajouterFait(BaseFaits* baseFaits, char valeur) {
    Proposition* nouvelleProposition = (Proposition*)malloc(sizeof(Proposition));
    if (nouvelleProposition != NULL) {
        nouvelleProposition->valeur = valeur;
        nouvelleProposition->suivante = baseFaits->propositions;
        baseFaits->propositions = nouvelleProposition;
    }
}

// Vérifier si un fait existe dans la base de faits
bool faitExiste(BaseFaits* baseFaits, char valeur) {
    Proposition* courante = baseFaits->propositions;

    while (courante != NULL) {
        if (courante->valeur == valeur) {
            return true;
        }
        courante = courante->suivante;
    }

    return false;
}
// Affiche une base de faits donnée
void afficherBaseFaits(BaseFaits* baseFaits) {
    Proposition* Courante = baseFaits->propositions;

    while (Courante != NULL) {
        printf("%c ", Courante->valeur);
        Courante = Courante->suivante;
    }

    printf("\n");
}




// Libère une proposition donnée d'une base de faits
void libererProposition(Proposition* proposition) {
    while (proposition != NULL) {
        Proposition* temp = proposition;
        proposition = proposition->suivante;
        free(temp);
    }
}

// Libère une règle donnée en libérant en même temps sa prémisse
void libererRegle(Regle* regle) {
    while (regle != NULL) {
        Proposition* premisseCourante = regle->premisse;
        while (premisseCourante != NULL) {
            Proposition* premisseSuivante = premisseCourante->suivante;
            free(premisseCourante);
            premisseCourante = premisseSuivante;
        }

        Regle* regleSuivante = regle->suivante;
        free(regle);
        regle = regleSuivante;
    }
}

// Libère une base de faits en libérant ses propositions
void libererBaseFaits(BaseFaits* baseFaits) {
    libererProposition(baseFaits->propositions);
}

// Libère une base de connaissance en libérant d'abord ses règles
void libererBaseConnaissances(BC* baseConnaissances) {
    libererRegle(baseConnaissances->regle);
    free(baseConnaissances);
}