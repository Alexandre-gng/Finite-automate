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
void printInformationsAutomate(automate A, vector<char> alphabet)
{
    vector<string> TEMPResVECTOR = checkDeterministe(A, alphabet);
    cout << "DETERMINISTE: ";
    if (stoi(TEMPResVECTOR[0]))
    {
        cout << "oui" << endl;
    }
    else
    {
        cout << "non (" << TEMPResVECTOR[1] << ")" << endl;
    }

    cout << "STANDARD: ";
    TEMPResVECTOR = checkStandard(A, alphabet);
    if (stoi(TEMPResVECTOR[0]))
    {
        cout << "oui" << endl;
    }
    else
    {
        cout << "non (" << TEMPResVECTOR[1] << ")" << endl;
    }

    cout << "COMPLET: ";
    TEMPResVECTOR = checkComplet(A, alphabet);
    if (stoi(TEMPResVECTOR[0]))
    {
        cout << "oui" << endl;
    }
    else
    {
        cout << "non (" << TEMPResVECTOR[1] << ")" << endl;
    }
    return;
}

// Vérifie si un automate est déterministe ou non
vector<string> checkDeterministe(automate A, vector<char> alphabet)
{
    vector<string> resTestStandard(2);
    resTestStandard[0] = "1";
    int cpt = 0;
    // Cas où l'automate a plusieurs entrées
    if (A.nbEtatsEntrees > 1)
    {
        resTestStandard[0] = "0";
        resTestStandard[1] = "il y a trop (" + to_string(A.nbEtatsEntrees) + ") d etats d'entrees dans cette automate.";
        return resTestStandard;
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
                    resTestStandard[0] = "0";
                    resTestStandard[1] = "il existe au moins un etat (etat #" + to_string(i) + ") avec au moins deux transitions sortantes de meme valeur";
                    return resTestStandard;
                }
            }
        }
    }
    resTestStandard[0] = "1";
    resTestStandard[1] = "Cette automate est déjà deterministe";
    return resTestStandard;
}

// Vérifie si un automate est standard
vector<string> checkStandard(automate A, vector<char> alphabet)
{
    vector<string> resTestStandard(2); // resTestStandard[0] = 1 si Standard et 0 si non standard // resTestStandard[1] = la raison de pourquoi il n'est pas standard 
    // Vérifie si l'automate a bien un seul état d'entrée
    if (A.nbEtatsEntrees > 1)
    {
        resTestStandard[0] = "0";
        resTestStandard[1] = "il y a trop (" + to_string(A.nbEtatsEntrees) + ") d etats d'entrees dans cette automate";
        return resTestStandard;
    }
    // Vérifie si aucune transition se dirige vers l'état d'entrée
    for (int i = 0; i < A.nbEtats; i++)
    {
        for (int m = 0; m < A.nbSymboles; m++)
        {
            for (int n = 0; n < A.nbEtats; n++) {
                if ((A.listeEtats[i]->listeEtatsSortants[m][n]) != NULL && (A.listeEtats[i]->listeEtatsSortants[m][n] == A.listeEtatsEntrees[0]))
                {
                    resTestStandard[0] = "0";
                    resTestStandard[1] = "il existe au moins une transition (" + to_string(i) + alphabet[m] + to_string(A.listeEtatsEntrees[0]->etatID) + ") entrante vers l etat d'entree";
                    return resTestStandard;
                }
            }
        }
    }
    resTestStandard[0] = "1";
    resTestStandard[1] = "Cette automate est déjà standard";
    return resTestStandard;
}

// Vérifie si un automate est complet
vector<string> checkComplet(automate A, vector<char> alphabet)
{
    vector<string> resTestStandard(2);
    for (int i = 0; i < A.nbEtats; i++)
    {
        for (int m = 0; m < A.nbSymboles; m++)
        {
            for (int n = 0; n < A.nbEtats; n++) {
                if (A.listeEtats[i]->listeEtatsSortants[m][n] != NULL)
                {
                    resTestStandard[0] = "0";
                    resTestStandard[1] = "il existe au moins un etat (#" + to_string(i) + " et " + alphabet[m] + ") qui ne possede pas de transition sortante d un des caracteres";
                    return resTestStandard;
                }
            }
        }
    }
    resTestStandard[0] = "1";
    resTestStandard[1] = "Cette automate est déjà complet";
    return resTestStandard;
}

// Standardise un automate
automate* standardisationAutomate(automate *A)
{
    automate* Astandard = A;
    etat* E = createEtat(Astandard->nbEtats, true, false, Astandard->nbSymboles, Astandard->nbEtats);
    
    int EtatEntrantAutomateID = 0;

    vector<int> TEMPSymboleINT;
    bool TEMPSortieEtat = false;
    for (auto CPT1 : Astandard->listeEtatsEntrees)
    {
        if (CPT1->sortie)
        {
            TEMPSortieEtat = true;
        }
        CPT1->entree = false;
        EtatEntrantAutomateID = CPT1->etatID;
        for (int m = 0; m < Astandard->nbEtats; m++)
        {
            TEMPSymboleINT.clear();
            for (int n = 0; n < Astandard->nbSymboles; n++) {
                if (CPT1->listeEtatsSortants[n][m] != NULL)
                {
                    TEMPSymboleINT.push_back(n);
                }
            }
            for (auto CPTSymbole : TEMPSymboleINT)
            {
                E->listeEtatsSortants[CPTSymbole][m] = Astandard->listeEtats[m];
            }
        }
    }
    // Augmentation de l'allocation mémoire de listeEtats VECTOR
    Astandard->listeEtats[Astandard->nbEtats] = E;
    Astandard->nbEtats ++;
    // Augmentation de l'allocation mémoire de listeEtatsEntrees VECTOR
    Astandard->listeEtatsEntrees.clear();
    Astandard->listeEtatsEntrees.resize(Astandard->nbEtats);
    Astandard->listeEtatsEntrees.push_back(E);
    // Augmentation de l'allocation mémoire de listeEtatsSorties VECTOR
    Astandard->listeEtatsSorties.resize(Astandard->nbEtats);
    if (TEMPSortieEtat)
    {
        Astandard->listeEtatsSorties[Astandard->nbEtats-1] = E;
    }
    Astandard->nbEtatsEntrees = 1;
    E->sortie = TEMPSortieEtat;
    E->entree = true;
    return Astandard;
}

// Déterminise un automate
automate* determinisationAutomate(automate* A)
{
    automate* ADeterministe = A;
    string TEMPSTRING;
    vector<string> TEMPLigneVECTOR;
    vector<string> VECTORNouveauxEtats;
    for (int i = 0; i < A->nbEtats; i++)
    {
        for (int n = 0; n < A->nbSymboles; n++)
        {
            TEMPSTRING = "";
            TEMPLigneVECTOR.clear();
            for (int l = 0; l < A->nbEtats; l++)
            {
                if (ADeterministe->listeEtats[i]->listeEtatsSortants[n][l] != NULL)
                {
                    TEMPSTRING = to_string(ADeterministe->listeEtats[i]->listeEtatsSortants[n][l]->etatID);
                    TEMPLigneVECTOR.push_back(TEMPSTRING);
                }
            }
            for (auto TEMPCPT : TEMPLigneVECTOR)
            {
                return A;
            }
        }
    }
    return A;
}

automate* completionAutomate(automate* A)
{
    automate* AComplet = A;
    etat* P = createEtat(55, false, false, AComplet->nbSymboles, AComplet->nbEtats);
    // Augmentation de l'allocation mémoire de listeEtats VECTOR
    AComplet->listeEtats[AComplet->nbEtats] = P;
    AComplet->nbEtats++;

    for (int i = 0; i < AComplet->nbEtats; i++)
    {

    }

    return A;
}

// Teste la reconnaissance d'un mot sur un automate
/*
bool testReconnaissanceMot(automate A, string mot)
{

    for (int i = 0)
}
*/


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

