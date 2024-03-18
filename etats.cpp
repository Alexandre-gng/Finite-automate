#include "automStruct.h"

etat* createEtat(int EtatID, bool Entree, bool Sortie, const int NB_SYMBOL, const int NB_ETATS)
{
    etat *E = new etat; // Alloue la mémoire à l'objet etat
    E->etatID = EtatID;
    E->entree = Entree;
    E->sortie = Sortie;

    E->listeEtatsSortants.resize(NB_SYMBOL);
    for (auto &symboleVector : E->listeEtatsSortants)
    {
        symboleVector.resize(NB_ETATS, nullptr);
    }

    E->listeEtatsEntrants.resize(NB_SYMBOL);
    for (auto& symboleVector : E->listeEtatsEntrants)
    {
        symboleVector.resize(NB_ETATS, nullptr);
    }
    return E;
}