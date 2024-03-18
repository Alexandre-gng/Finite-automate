#ifndef AUTOMATE_AUTOMSTRUCT_H
#define AUTOMATE_AUTOMSTRUCT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ========================= structure etat =========================
typedef struct etat {
    vector<vector<etat*>> listeEtatsSortants;
    vector<vector<etat*>> listeEtatsEntrants;
    int etatID;
    bool entree;
    bool sortie;
} etat;

// ========================= structure automate =========================
typedef struct automate {
    int nbSymboles, nbTransitions;
    int nbEtats, nbEtatsEntrees, nbEtatsSorties;
    vector<etat*> listeEtats;
    vector<etat*> listeEtatsEntrees;
    vector<etat*> listeEtatsSorties;
} automate;


// ========================= parsing =========================
// Récupération des données du fichier texte
automate parsing(vector<char>);


// ========================= Fonctions ciblant un automate =========================
// Créer un automate
automate createAutomate(int, int , int , int , int , vector<etat*>, vector<etat*>, vector<etat*>);
// Affichage du tableau de l'automate
void printAutomate(automate, vector<char>);
// Affichage des informations sur l'automate
void printInformationsAutomate(automate);
// Vérifie si un automate est déterministe
int checkDeterministe(automate);
// Vérifie si un automate est standard
int checkStandard(automate);
// Vérifie si un automate est complet
int checkComplet(automate);

// Standardise un automate
automate* standardisationAutomate(automate*);

// ========================= Fonctions ciblant un état =========================
// Créer un état
etat* createEtat(int, bool, bool, int, int);


// ========================= Fonctions générales =========================
// Vérifie si un INT est dans vector<int>
bool verifINTinVECTOR(int, vector<int>);
// Vérifie si un CHAR est dans vector<char>
int indexCHARinVECTOR(char, vector<char>);

#endif //AUTOMATE_AUTOMSTRUCT_H
