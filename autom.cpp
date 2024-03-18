#include "automStruct.h"

using namespace std;

automate createAutomate(int nbtransitions,int nbsymboles, int nbetats, int nbetatsentrees, int nbetatssorties, vector<etat*> listeEtatsEntrees, vector<etat*> listeEtatsSortie, vector<etat*> listeEtats)
{
    automate A;
    A.nbEtats = nbetats;
    A.nbSymboles = nbsymboles;
    A.listeEtats = listeEtats;
    A.listeEtatsEntrees = listeEtatsEntrees;
    A.listeEtatsSorties = listeEtatsSortie;
    A.nbEtatsEntrees = nbetatsentrees;
    A.nbEtatsSorties = nbetatssorties;
    A.nbTransitions = nbtransitions;
    return A;
}

// Affiche un automate sous forme de tableau
void printAutomate(automate A, vector<char> alphabet)
{
    // 2*nbEtats - 1 = nb caractère ds les colonnes [1; nbSymboles]
    int TEMPcpt = 0;
    vector<int> TEMPlisteINT;
    cout << "    | etats |";
    for (int i = 0; i<A.nbSymboles; i++)
    {
        for (int k = 0; k < A.nbEtats; k++)
        {
            cout << " ";
        }
        cout << alphabet[i];
        for (int k = 0; k < A.nbEtats; k++)
        {
            cout << " ";
        }
        cout << "|";
    }
    for (int j = 0; j < A.nbEtats; j++)
    {
        if ((A.listeEtats[j]->entree == true) && (A.listeEtats[j]->sortie == true)) // Si état d'entrée et de sortie
        {
            cout << "\nE/S |   ";
            cout << A.listeEtats[j]->etatID << "   |";
        }
        if ((A.listeEtats[j]->entree == true) && (A.listeEtats[j]->sortie == false)) // Si état d'entrée
        {
            cout << "\n E  |   ";
            cout << A.listeEtats[j]->etatID << "   |";
            for (int m = 0; m < A.nbSymboles; m++)
            {
                TEMPcpt = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    cout << TEMPlisteINT[d];
                }
                for (int q = 0; q < A.nbEtats*A.nbSymboles+1-TEMPcpt*2; q++)
                {
                    cout << " ";
                }
                cout << "|";
            }
        }
        if ((A.listeEtats[j]->entree == false) && (A.listeEtats[j]->sortie == true)) // Si état de sortie
        {
            cout << "\n S  |   ";
            cout << A.listeEtats[j]->etatID << "   |";
            for (int m = 0; m < A.nbSymboles; m++)
            {
                TEMPcpt = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    cout << TEMPlisteINT[d];
                }
                for (int q = 0; q < A.nbEtats*A.nbSymboles+1-TEMPcpt*2; q++)
                {
                    cout << " ";
                }
                cout << "|";
            }
        }
        if ((A.listeEtats[j]->entree == false) && (A.listeEtats[j]->sortie == false)) // Si état sans sortie/ entrée
        {
            cout << "\n    |   ";
            cout << A.listeEtats[j]->etatID << "   |";
            for (int m = 0; m < A.nbSymboles; m++)
            {
                TEMPcpt = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    cout << TEMPlisteINT[d];
                }
                for (int q = 0; q < A.nbEtats*A.nbSymboles+1-TEMPcpt*2; q++)
                {
                    cout << " ";
                }
                cout << "|";
            }
        }
    }
    cout << "\n" << endl;
    return;
}

// Afficher les information sur un automate
void printInformationsAutomate(automate A)
{
    cout << "DETERMINISTE: ";
    if (checkDeterministe(A))
    {
        cout << "oui" << endl;
    }
    else
    {
        cout << "non" << endl;
    }

    cout << "STANDARD: ";
    if (checkStandard(A))
    {
        cout << "oui" << endl;
    }
    else
    {
        cout << "non" << endl;
    }

    cout << "COMPLET: ";
    if (checkComplet(A))
    {
        cout << "oui" << endl;
    }
    else
    {
        cout << "non" << endl;
    }
    return;
}

// Vérifie si un automate est déterministe ou non
int checkDeterministe(automate A)
{
    int cpt = 0;
    // Cas où l'automate a plusieurs entrées
    if (A.nbEtatsEntrees > 1)
    {
        return 0;
    }
    // Cas où un état possède plus de 1 transition sortante d'une même lettre
    for (int i = 0; i < A.nbEtats; i++)
    {
        for (int m = 0; m < A.nbSymboles; m++)
        {
            cpt = 0;
            for (int n = 0; n < A.nbEtats; n++) {
                if (A.listeEtats[i]->listeEtatsSortants[m][n] != NULL)
                {
                    cpt++;
                }
                if (cpt > 1)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Vérifie si un automate est standard
int checkStandard(automate A)
{
    // Vérifie si l'automate a bien un seul état d'entrée
    if (A.nbEtatsEntrees > 1)
    {
        return 0;
    }
    // Vérifie si aucunne transition se dirige vers l'état d'entrée
    for (int i = 0; i < A.nbEtats; i++)
    {
        for (int m = 0; m < A.nbSymboles; m++)
        {
            for (int n = 0; n < A.nbEtats; n++) {
                if ((A.listeEtats[i]->listeEtatsSortants[m][n]) != NULL && (A.listeEtats[i]->listeEtatsSortants[m][n] == A.listeEtatsEntrees[0]))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Vérifie si un automate est complet
int checkComplet(automate A)
{
    for (int i = 0; i < A.nbEtats; i++)
    {
        for (int m = 0; m < A.nbSymboles; m++)
        {
            for (int n = 0; n < A.nbEtats; n++) {
                if (A.listeEtats[i]->listeEtatsSortants[m][n] != NULL)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Standardise un automate
automate* standardisationAutomate(automate *A)
{
    automate* Astandard = A;
    etat* E; E->entree = true;

    int EtatEntrantAutomateID = 0;
    vector<int> TEMPchar;
    for (auto CPT1: Astandard->listeEtatsEntrees)
    {
        TEMPchar.clear();
        EtatEntrantAutomateID = CPT1->etatID;
        for (int m = 0; m < Astandard->nbSymboles; m++)
        {
            for (int n = 0; n < Astandard->nbEtats; n++) {
                if (CPT1->listeEtatsEntrants[m][n] != NULL)
                {
                    TEMPchar.push_back(m);
                }
            }
        }
    }
    return Astandard;
}


// Vérifie la présence d'un INT dans un vector<int>
bool verifINTinVECTOR(int a, vector<int> v)
{
    for (auto i: v)
    {
        if (i == a)
        {
            return true;
        }
    }
    return false;
}
// Vérifie la présence d'un CHAR dans un vector<CHAR>
bool verifCHARinVECTOR(char a, vector<char> v)
{
    for (auto i: v)
    {
        if (i == a)
        {
            return true;
        }
    }
    return false;
}
// Retourne l'index d'un caractère dans un vector<string>
int indexCHARinVECTOR(char a, vector<char> v)
{
    int cpt = 0;
    for (auto k: v)
    {
        if (k == a)
        {
            return cpt;
        }
        else
        {
            cpt++;
        }
    }
}

