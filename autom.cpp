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
    int sizeMax = 1;
    for (auto TEMP : A.listeEtats)
    {
        if (TEMP->name.size() > sizeMax )
        {
            sizeMax = TEMP->name.size();
        }
    }
    // 2*nbEtats - 1 = nb caractère ds les colonnes [1; nbSymboles]
    int TEMPcpt = 0;
    int IDEtatP = -1; int IDEtatI = -1;
    vector<int> TEMPlisteINT;

    // Obtention de l'ID de l'état poubelle et initial
    for (auto i : A.listeEtats)
    {
        if (i->name == "P")
        {
            IDEtatP = i->etatID;
        }
        if (i->name == "i")
        {
            IDEtatI = i->etatID;
        }
    }
    cout << "    | etats";
    for (int c = 0; c < sizeMax; c++)
    {
        cout << " ";
    }
    cout << "|";
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
        if (A.listeEtats[j]->entree && A.listeEtats[j]->sortie) // Si état d'entrée et de sortie
        {
            cout << "\nE/S |   ";
            if (A.listeEtats[j]->name == "")
            {
                cout << A.listeEtats[j]->etatID;
            }
            else
            {
                cout << A.listeEtats[j]->name;
                for (int c = 0; c < 3 + sizeMax - A.listeEtats[j]->name.size(); c++)
                {
                    cout << " ";
                }
                cout << "|";
            }

            for (int m = 0; m < A.nbSymboles; m++) // TOUTE CETTE BOUCLE EST UN PUR COPIE/COLLE, ATTENDRE D'AUTRES TESTS POUR VALIDER
            {
                TEMPcpt = 0;
                bool TEMPbool0 = true;
                int TEMPcpt2 = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                        TEMPbool0 = false;
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    if (A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name != "")
                    {
                        cout << A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name;
                        TEMPcpt2 += A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name.size();
                    }
                    else
                    {
                        cout << TEMPlisteINT[d];
                    }
                }
                if (!TEMPbool0)
                {
                    for (int q = 0; q < A.nbEtats * 2 - TEMPcpt2; q++)
                    {
                        cout << " ";
                    }
                }
                else
                {
                    for (int q = 0; q < A.nbEtats * 2 + 1; q++)
                    {
                        cout << " ";
                    }
                }
                cout << "|";
            }
        }
        if ((A.listeEtats[j]->entree) && (!A.listeEtats[j]->sortie)) // Si état d'entrée
        {

            cout << "\n E  |   ";
            if (A.listeEtats[j]->name == "")
            {
                cout << A.listeEtats[j]->etatID << "   |";
            }
            else
            {
                cout << A.listeEtats[j]->name;
                for (int c = 0; c < 3 + sizeMax - A.listeEtats[j]->name.size(); c++)
                {
                    cout << " ";
                }
                cout << "|";
            }
            for (int m = 0; m < A.nbSymboles; m++)
            {
                TEMPcpt = 0;
                bool TEMPbool0 = true;
                int TEMPcpt2 = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                        TEMPbool0 = false;
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    if (A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name != "")
                    {
                        cout << A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name;
                        TEMPcpt2 += A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name.size();
                    }
                    else
                    {
                        cout << TEMPlisteINT[d];
                    }
                }
                if (!TEMPbool0)
                {
                    for (int q = 0; q < A.nbEtats * 2 - TEMPcpt2; q++)
                    {
                        cout << " ";
                    }
                }
                else
                {
                    for (int q = 0; q < A.nbEtats * 2 + 1; q++)
                    {
                        cout << " ";
                    }
                }
                cout << "|";
            }
        }
        if (!(A.listeEtats[j]->entree) && (A.listeEtats[j]->sortie)) // Si état de sortie
        {
            cout << "\n S  |   ";
            if (A.listeEtats[j]->name == "")
            {
                cout << A.listeEtats[j]->etatID << "   |";
            }
            else
            {
                cout << A.listeEtats[j]->name;
                for (int c = 0; c < 3 + sizeMax - A.listeEtats[j]->name.size(); c++)
                {
                    cout << " ";
                }
                cout << "|";
            }
            for (int m = 0; m < A.nbSymboles; m++)
            {
                TEMPcpt = 0;
                bool TEMPbool0 = true;
                int TEMPcpt2 = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                        TEMPbool0 = false;
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    if (A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name != "")
                    {
                        cout << A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name;
                        TEMPcpt2 += A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name.size();
                    }
                    else
                    {
                        cout << TEMPlisteINT[d];
                    }
                }
                if (!TEMPbool0)
                {
                    for (int q = 0; q < A.nbEtats * 2 - TEMPcpt2; q++)
                    {
                        cout << " ";
                    }
                }
                else
                {
                    for (int q = 0; q < A.nbEtats * 2 + 1; q++)
                    {
                        cout << " ";
                    }
                }
                cout << "|";
            }
        }
        if (!(A.listeEtats[j]->entree) && !(A.listeEtats[j]->sortie)) // Si état sans sortie/ entrée
        {
            cout << "\n    |   ";
            if (A.listeEtats[j]->name == "")
            {
                cout << A.listeEtats[j]->etatID << "   |";
            }
            else
            {
                cout << A.listeEtats[j]->name;
                for (int c = 0; c < 3 + sizeMax - A.listeEtats[j]->name.size(); c++)
                {
                    cout << " ";
                }
                cout << "|";
            }
            for (int m = 0; m < A.nbSymboles; m++)
            {
                TEMPcpt = 0;
                bool TEMPbool0 = true;
                int TEMPcpt2 = 0;
                TEMPlisteINT.clear();
                for (int s = 0; s < A.nbEtats; s++)
                {
                    if (A.listeEtats[j]->listeEtatsSortants[m][s] != NULL)
                    {
                        TEMPcpt++;
                        TEMPlisteINT.push_back(A.listeEtats[j]->listeEtatsSortants[m][s]->etatID);
                        TEMPbool0 = false;
                    }
                }
                for (int d = 0; d < TEMPcpt; d++)
                {
                    cout << " ";
                    if (A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name != "")
                    {
                        cout << A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name;
                        TEMPcpt2 += A.listeEtats[j]->listeEtatsSortants[m][TEMPlisteINT[d]]->name.size();
                    }
                    else
                    {
                        cout << TEMPlisteINT[d];
                    }
                }
                if (!TEMPbool0)
                {
                    for (int q = 0; q < A.nbEtats * 2 - TEMPcpt2; q++)
                    {
                        cout << " ";
                    }
                }
                else
                {
                    for (int q = 0; q < A.nbEtats * 2 + 1; q++)
                    {
                        cout << " ";
                    }
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
    cout << "\nDETERMINISTE: ";
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
                    resTestStandard[1] = "il existe au moins un etat (etat #" + A.listeEtats[i]->name + ") avec au moins deux transitions sortantes de meme valeur";
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
    int cpt = 0;
    vector<string> resTestStandard(2);
    for (int i = 0; i < A.nbEtats; i++)
    {
        for (int m = 0; m < A.nbSymboles; m++)
        {
            int cpt = 0;
            for (int n = 0; n < A.nbEtats; n++)
            {
                if (A.listeEtats[i]->listeEtatsSortants[m][n] == NULL)
                {
                    cpt++;
                }
                if (cpt == A.nbEtats)
                {
                    resTestStandard[0] = "0";
                    resTestStandard[1] = "il existe au moins un etat (#" + A.listeEtats[i]->name + ") qui ne possede pas de transition sortante en " + alphabet[m] + ")";
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
automate standardisationAutomate(automate *A)
{
    automate Astandard = *A;
    automate* P_Astandard = &Astandard;
    etat* E = createEtat(P_Astandard->nbEtats, true, false, P_Astandard->nbSymboles, P_Astandard->nbEtats);
    E->name = *"i";

    int EtatEntrantAutomateID = 0;

    vector<int> TEMPSymboleINT;
    bool TEMPSortieEtat = false;
    for (auto CPT1 : P_Astandard->listeEtatsEntrees)
    {
        if (CPT1->  sortie)
        {
            TEMPSortieEtat = true;
        }
        CPT1->entree = false;
        EtatEntrantAutomateID = CPT1->etatID;
        for (int m = 0; m < P_Astandard->nbEtats; m++)
        {
            TEMPSymboleINT.clear();
            for (int n = 0; n < P_Astandard->nbSymboles; n++) {
                if (CPT1->listeEtatsSortants[n][m] != NULL)
                {
                    TEMPSymboleINT.push_back(n);
                }
            }
            for (auto CPTSymbole : TEMPSymboleINT)
            {
                E->listeEtatsSortants[CPTSymbole][m] = P_Astandard->listeEtats[m];
            }
        }
    }
    // Augmentation de l'allocation mémoire de listeEtats VECTOR
    P_Astandard->listeEtats[P_Astandard->nbEtats] = E;
    P_Astandard->nbEtats ++;
    // Augmentation de l'allocation mémoire de listeEtatsEntrees VECTOR
    P_Astandard->listeEtatsEntrees.clear();
    P_Astandard->listeEtatsEntrees.resize(P_Astandard->nbEtats);
    P_Astandard->listeEtatsEntrees.push_back(E);
    // Augmentation de l'allocation mémoire de listeEtatsSorties VECTOR
    P_Astandard->listeEtatsSorties.resize(P_Astandard->nbEtats);
    if (TEMPSortieEtat)
    {
        P_Astandard->listeEtatsSorties[P_Astandard->nbEtats-1] = E;
    }
    P_Astandard->nbEtatsEntrees = 1;
    E->sortie = TEMPSortieEtat;
    E->entree = true;
    return Astandard;
}

// Déterminise un automate
automate determinisationAutomate(automate* A)
{
    automate ADeterministe = createAutomate(A->nbTransitions, A->nbSymboles, A->nbEtats, A->nbEtatsEntrees, A->nbEtatsSorties, A->listeEtatsEntrees, A->listeEtatsSorties, A->listeEtats);
    automate* P_ADeterministe = &ADeterministe;
    string TEMPSTRING;
    vector<string> TEMPLigneVECTOR; // Vérifie si on doit arrêter la determinsation
    vector<string> VECTORNouveauxEtats(1);
    vector<int> TEMPINTEtatsSortants; // Liste des etats vers lesquels l'état étudié se dirige
    int cpt = 1; bool sor = false;
    // Récupération des états d'entrées de A
    for (auto i : A->listeEtatsEntrees)
    {
        if (i != NULL)
        {
            VECTORNouveauxEtats[0] += i->name;
            if (i->sortie)
            {
                sor = true;
            }
        }
    }
    // Création et ajout de l'etat d'entré de ADeterministe
    etat* E0 = createEtat(cpt-1, true, sor, A->nbSymboles, A->nbEtats);
    E0->name = VECTORNouveauxEtats[0];
    P_ADeterministe->listeEtatsEntrees.resize(0);
    P_ADeterministe->listeEtatsEntrees.push_back(E0);
    P_ADeterministe->listeEtatsSorties.resize(0);
    P_ADeterministe->listeEtats.resize(0);
    P_ADeterministe->listeEtats.push_back(E0);

    P_ADeterministe->nbEtatsSorties = 0;
    // PREMIERE PARTIE: RECUPERATION DES NOUVEAUX ETATS DE L'AUTOMATE
    for (int i = 0; i < cpt; i++)
    {
        TEMPLigneVECTOR.clear();
        //string en = VECTORNouveauxEtats[VECTORNouveauxEtats.size() - 1];
        string en = VECTORNouveauxEtats[i];
        for (int s = 0; s < A->nbSymboles; s++)
        {
            TEMPSTRING = "";
            TEMPINTEtatsSortants.resize(0);
            for (auto TEMPs : en)
            {
                int TEMPsTEMP = TEMPs - '0';
                for (int es = 0; es < A->nbEtats; es++)
                {
                    if (A->listeEtats[TEMPsTEMP]->listeEtatsSortants[s][es] != NULL)
                    {
                        TEMPSTRING += to_string(A->listeEtats[TEMPsTEMP]->listeEtatsSortants[s][es]->etatID);
                        TEMPINTEtatsSortants.push_back(es);
                    }
                }
            }
            // Conditions afin de créer un nouvel état:
            // 1. Qu'il n'existe pas déjà
            // 2. Qu'il existe (ex e.name = "")
            // 3. Qu'il n'y ai pas de doublon (ex: e.name = "022")
            if (verifDoubleCHARinSTRING(TEMPSTRING))
            {
                string T;
                for (auto a: TEMPSTRING)
                {
                    if (!verifCHARinSTRING(a, T))
                    {
                        T += a;
                    }
                }
                TEMPSTRING = T;
            }

            sort(TEMPSTRING.begin(), TEMPSTRING.end());
            if (!verifSTRINGinVECTOR(TEMPSTRING, VECTORNouveauxEtats) && TEMPSTRING != "")
            {
                VECTORNouveauxEtats.push_back(TEMPSTRING);
                cpt++;
                bool sor = false;
                for (char b : TEMPSTRING)
                {
                    if (A->listeEtats[(b - '0')]->sortie)
                    {
                        sor = true;
                        break;
                    }
                }
                // Création et ajout nouvel état
                etat* E = createEtat(cpt - 1, false, sor, A->nbSymboles, A->nbEtats);
                E->name = TEMPSTRING;
                E->etatID = cpt - 1;
                if (E->sortie)
                {
                    P_ADeterministe->listeEtatsSorties.push_back(E);
                    P_ADeterministe->nbEtatsSorties ++;
                }
                P_ADeterministe->listeEtats.push_back(E);
                TEMPINTEtatsSortants.resize(0);
            }
            else
            {
                TEMPLigneVECTOR.push_back(TEMPSTRING);
            }
        }
    }

    // SECONDE PARTIE, CONNEXION DES :
    vector<int> TEMPINTListeSortants;
    vector<int> TEMPINTListeEntrants;
    for (auto TEMPetat : P_ADeterministe->listeEtats)
    {
        etat* E = TEMPetat;
        // Création des listes de sortants et d'entrants pour chaque symbole
        for (int s = 0; s < A->nbSymboles; s++)
        {
            TEMPINTListeEntrants.clear();
            TEMPINTListeSortants.clear();

            // Pour chaque état contenu dans l'état courant de P_ADeterministe
            for (auto TEMPMiniEtat : TEMPetat->name)
            {
                //int TEMPMiniEtatINT = TEMPMiniEtat - '0';
                int TEMPMiniEtatINT;
                if (TEMPMiniEtat - '0' <= 10)
                {
                    TEMPMiniEtatINT = TEMPMiniEtat - '0';
                }
                else
                {
                    TEMPMiniEtatINT = TEMPetat->etatID;
                }
                // Pour chaque état de A
                for (int e = 0; e < A->nbEtats; e++)
                {
                    // Si l'état courant de P_ADeterministe contient un état qui a une transition sortante vers l'état e de A avec le symbole s
                    // A.listeEtats[1]->listeEtatsSortants[0][2]->name << end;
                    if (A->listeEtats[TEMPMiniEtatINT]->listeEtatsSortants[s][e] != NULL)
                    {
                        TEMPINTListeSortants.push_back(A->listeEtats[TEMPMiniEtatINT]->listeEtatsSortants[s][e]->etatID);
                    }
                    // Si l'état courant de P_ADeterministe contient un état qui a une transition entrante depuis l'état e de A avec le symbole s
                    if (A->listeEtats[TEMPMiniEtatINT]->listeEtatsEntrants[s][e] != NULL)
                    {
                        TEMPINTListeEntrants.push_back(A->listeEtats[TEMPMiniEtatINT]->listeEtatsEntrants[s][e]->etatID);
                    }
                }
            }
            string a = "";
            // Concaténation de tous les états sortants de TEMPetat
            for (int x = 0; x < TEMPINTListeSortants.size(); x++)
            {
                a += to_string(TEMPINTListeSortants[x]);
            }
            // Cas où deux états pointent vers un même état (ex: a = 22)
            if (verifDoubleCHARinSTRING(a))
            {
                string T;
                for (auto v: a)
                {
                    if (!verifCHARinSTRING(v, T))
                    {
                        T += v;
                    }
                }
                a = T;
            }
            // Concaténation de tous les états entrants de TEMPetat
            string b = "";
            for (int x = 0; x < TEMPINTListeEntrants.size(); x++)
            {
                b += to_string(TEMPINTListeEntrants[x]);
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            // Ajout états sortants
            for (auto x: P_ADeterministe->listeEtats)
            {
                if (x->name == a)
                {
                    TEMPetat->listeEtatsSortants[s][x->etatID] = x;
                }
            }
            // Ajout états entrants
            for (auto x: P_ADeterministe->listeEtats)
            {
                if (x->name == b)
                {
                    TEMPetat->listeEtatsEntrants[s][x->etatID] = x;
                }
            }
        }
    }
    P_ADeterministe->nbEtatsEntrees = 1;
    P_ADeterministe->nbEtats = cpt;
    P_ADeterministe->nbTransitions = cpt * P_ADeterministe->nbSymboles;
    return ADeterministe;
}


// Complète un automate
automate completionAutomate(automate* A)
{
    automate AComplet = *A;
    automate* P_AComplet = &AComplet;
    etat* P = createEtat(P_AComplet->nbEtats, false, false, P_AComplet->nbSymboles, P_AComplet->nbEtats);
    P->name = *"P";
    // Augmentation de l'allocation mémoire de listeEtats VECTOR
    P_AComplet->nbEtats++;
    P_AComplet->listeEtats.resize(P_AComplet->nbEtats);
    P_AComplet->listeEtats[P_AComplet->nbEtats-1] = P;
    for (int i = 0; i < P_AComplet->nbSymboles; i++)
    {
        P->listeEtatsEntrants[i][P->etatID] = P;
        P->listeEtatsSortants[i][P->etatID] = P;
    }
    for (int i = 0; i < P_AComplet->nbEtats; i++)
    {
        for (int m = 0; m < P_AComplet->nbSymboles; m++)
        {
            int cpt = 0;
            for (int n = 0; n < P_AComplet->nbEtats; n++)
            {
                if (P_AComplet->listeEtats[i]->listeEtatsSortants[m][n] == NULL)
                {
                    cpt++;
                }
                if (cpt == P_AComplet->nbEtats)
                {
                    P_AComplet->listeEtats[i]->listeEtatsSortants[m][n] = P;
                    P->listeEtatsEntrants[m][i] = P_AComplet->listeEtats[i];
                    break;
                }
            }
        }
    }
    return AComplet;
}


// Donne un automate reconaissant le langage complémentaire
automate complementAutomate(automate* A)
{
    automate AComplement = *A;
    automate* P_AComplement = &AComplement;

    for (auto e : P_AComplement->listeEtats)
    {
        if (e->sortie)
            e->sortie = false;
        else
            e->sortie = true;
    }

    return AComplement;
}

void freeAutomate(automate* A)
{
    for (int i = 0; i < A->nbEtats; i++) {
        for (int s = 0; s < A->nbSymboles; s++) {
            for (int j = 0; j < A->nbEtats; j++) {
                if (A->listeEtats[i]->listeEtatsSortants[s][j] != NULL)
                    A->listeEtats[i]->listeEtatsSortants[s][j] = NULL;
                if (A->listeEtats[i]->listeEtatsEntrants[s][j] != NULL)
                    A->listeEtats[i]->listeEtatsEntrants[s][j] = NULL;
            }
        }
    }
    A->nbEtats = 0;
    A->nbSymboles = 0;
    A->nbEtatsEntrees = 0;
    A->nbEtatsSorties = 0;
    A->nbTransitions = 0;
}

vector<bool> testReconnaissanceMot(automate &A, vector<string> &mots) {
    vector<bool> resultats(mots.size());
    cout << "T0" << endl;
    for (int i = 0; i < mots.size(); i++) {
        string mot = mots[i];
        int longueurMot = mot.length();

        // Parcours en largeur pour vérifier si le mot est accepté par l'automate
        queue<etat*> fileEtats;
        vector<etat*> etatsCourants;

        // Ajouter les états d'entrée à la file
        for (etat* e : A.listeEtatsEntrees) {
            fileEtats.push(e);
        }
        cout << "T1" << endl;
        // Parcourir le mot caractère par caractère
        for (int j = 0; j < longueurMot; j++) {
            int tailleFile = fileEtats.size();
            cout << "T2" << endl;
            // Traiter chaque état dans la file actuelle
            for (int k = 0; k < tailleFile; k++) {
                etat* etatCourant = fileEtats.front();
                fileEtats.pop();

                // Vérifier les transitions pour le caractère courant
                int indiceSymbole = mot[j] - 'a';
                if (indiceSymbole >= 0 && indiceSymbole < A.nbSymboles &&
                    j < longueurMot - 1) {
                    // Ajouter les états suivants à la file (s'il en existe)
                    if (!etatCourant->listeEtatsSortants[indiceSymbole].empty()) {
                        for (etat* e : etatCourant->listeEtatsSortants[indiceSymbole]) {
                            fileEtats.push(e);
                        }
                    }
                } else {
                    // Stocker les états courants pour le dernier caractère
                    etatsCourants.push_back(etatCourant);
                }
            }
        }

        // Vérifier si l'un des états courants est un état de sortie
        resultats[i] = false;
        for (etat* e : etatsCourants) {
            if (e->sortie) {
                resultats[i] = true;
                break;
            }
        }
    }
    for (int i = 0; i<resultats.size(); i++)
    {
        cout << " MOT #" << i << " = " << resultats[i] << endl;
    }
    return resultats;
}

// Teste la reconnaissance d'une liste de mots sur un automate
vector<bool> testReconnaissanceListeMots(automate A, vector<string> LISTEmot)
{
    int cpt = 0;
    // Résultat de chaque mot: le res de LISTEmot[i] est à l'indice i de resVECTOR
    vector<bool> resVECTOR(LISTEmot.size() - 1, false);

    for (int i = 0; i < LISTEmot.size(); i++)
    {
        resVECTOR[i] = testReconnaissanceMot(A, LISTEmot[i]);

    }
    return resVECTOR;
}

// Test reconnaissance d'un seul mot sur un automate
bool testReconnaissanceMot(automate A, string mot)
{
    int motSize = mot.size();
    int res = 0;
    // Cas du mot vide
    if (mot == "*")
    {
        for (auto EE: A.listeEtatsEntrees)
        {
            if (EE->sortie == true)
            {
                return true;
            }
        }
        return false;
    }
    for (auto EE: A.listeEtatsEntrees)
    {
        res = 0;
        int cpt = 0;
        etat* EActuel = EE;
        // Vérifie si l'état d'entrée est un état de sortie
        for (int cara = 0; cara < A.nbSymboles; cara++)
        {
            if (res == 1)
            {
                res = 0;
                cara = 0;
            }
            for (int e = 0; e < A.nbEtats; e++)
            {
                if (res == 1)
                {
                    cara = 0;
                    e = 0;
                    res = 0;
                }
                if (EActuel->listeEtatsSortants[cara][e] != NULL && cpt < motSize && EActuel->listeEtatsSortants[cara][e]->name != "P")
                {
                    cpt ++;
                    EActuel = EActuel->listeEtatsSortants[cara][e];
                    e = 0;
                    cara = 0;
                    res = 1;
                    if (EActuel->sortie && cpt == motSize)
                    {
                        return true;
                    }
                }
                if (cpt == motSize)
                {
                    break;
                }
            }
        }
    }
    return false;
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
// Vérifie la présence d'un STRING dans un vector<STRING>
bool verifSTRINGinVECTOR(string a, vector<string> v)
{
    for (string i : v)
    {
        if (i == a)
        {
            return true;
        }
    }
    return false;
}

// Vérifie si un CHAR est présent plusieurs fois dans un STRING
bool verifDoubleCHARinSTRING(string S)
{
    int cpt = 0;
    for (char a: S)
    {
        for (char b: S) {
            if (b == a)
            {
                cpt ++;
            }
            if (cpt == 2)
            {
                return true;
            }
        }
    }
    return false;
}

// Vérifie la présence d'un CHAR dans un STRING
bool verifCHARinSTRING(char a, string S)
{
    for (auto i: S)
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
    return cpt;
}
// Retourne l'index d'un caractère dans un string
int indexCHARinSTRING(char a, string s)
{
    int cpt = 0;
    for (char k : s)
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
    return -1;
}