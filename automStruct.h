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
    string name;
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
// Crée un automate
automate createAutomate(int, int , int , int , int , vector<etat*>, vector<etat*>, vector<etat*>);
// Affichage du tableau de l'automate
void printAutomate(automate, vector<char>);
// Affichage des informations sur l'automate
void printInformationsAutomate(automate, vector<char>);
// Vérifie si un automate est déterministe
vector<string> checkDeterministe(automate, vector<char>);
// Vérifie si un automate est standard
vector<string> checkStandard(automate, vector<char>);
// Vérifie si un automate est complet
vector<string> checkComplet(automate, vector<char>);

// Standardise un automate
automate standardisationAutomate(automate*);
// Déterminise un automate
automate determinisationAutomate(automate*);
// Complète un automate
automate completionAutomate(automate*);
// Complément du langage d'un automate
automate complementAutomate(automate*);


// Test de reconnaissance d'un mot
bool testReconnaissanceMot(automate, vector<string>);


// ========================= Fonctions ciblant un état =========================
// Créer un état
etat* createEtat(int, bool, bool, int, int);


// ========================= Fonctions générales =========================
// Vérifie si un INT est dans vector<int>
bool verifINTinVECTOR(int, vector<int>);
// Vérifie si un CHAR est dans vector<char>
bool verifCHARinVECTOR(char, vector<char>);
// Vérifie si un STRING est dans vector<string>
bool verifSTRINGinVECTOR(string, vector<string>);
// Retourne l'index d'un caractère dans un vector<string>
int indexCHARinVECTOR(char, vector<char>);

#endif //AUTOMATE_AUTOMSTRUCT_H
