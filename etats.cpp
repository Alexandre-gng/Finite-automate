#include "automStruct.h"

etat* createEtat(int EtatID, bool Entree, bool Sortie, int NB_SYMBOL, int NB_ETATS)
{
    NB_ETATS++;
    etat *E = new etat; // Alloue la mémoire à l'objet etat
    E->etatID = EtatID;
    E->entree = Entree;
    E->sortie = Sortie;
    E->name = to_string(EtatID);
    // Alocation mémoire de listeEtatsSortants
    E->listeEtatsSortants.resize(NB_SYMBOL+1);
    for (auto &symboleVector : E->listeEtatsSortants)
    {
        symboleVector.resize(NB_ETATS + 1, nullptr);
    }
    // Alocation mémoire de listeEtatsEntrants
    E->listeEtatsEntrants.resize(NB_SYMBOL+1);
    for (auto& symboleVector : E->listeEtatsEntrants)
    {
        symboleVector.resize(NB_ETATS + 1, nullptr);
    }
    // pow(2, NB_ETATS)
    return E;
}
