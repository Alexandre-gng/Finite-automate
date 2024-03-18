#include "automStruct.h"

using namespace std;

vector<char> listeSymbole;

int nbSymboles, nbEtats, nbEtatsEntrees, nbEtatsSorties, nbTransitions;
vector<int> INTlisteEtatsEntrees; vector<int> INTlisteEtatsSorties;
vector<etat*> listeEtatsEntrees; vector<etat*> listeEtatsSorties;
vector<etat*> listeEtats;

etat *E;

ifstream monFlux("C:/Users/alexa/OneDrive/Bureau/Automate projet/automate/file.txt");
double nombre;

// Récupère tout le contenu du fichier txt et le convertit en automate
automate parsing(vector<char> alphabet)
{
    if (monFlux)
    {
        // Récupère le nombre d'états et de symboles
        for (int i = 0; i < 3; i++)
        {
            monFlux >> nombre;
            //if (isdigit(nombre) == 1) // Verifie que le caractère issu du .txt est un nombre
            if (i == 0)
            {
                nbSymboles = nombre;
                // Récupère une liste des symboles de l'automate
                for (int k = 0; k < nbSymboles; k++)
                {
                    listeSymbole.push_back(alphabet[k]);
                }
            }
            if (i == 1)
            {
                nbEtats = nombre;
            }
            if (i ==2)
            {
                nbEtatsEntrees = nombre;
            }
        }

        // Récupère la liste des états d'entrée
        for (int i = 0; i != nbEtatsEntrees; i++)
        {
            monFlux >> nombre;
            INTlisteEtatsEntrees.push_back(nombre);
        }

        // Récupère la liste des états de sortie
        monFlux >> nombre;
        nbEtatsSorties = nombre;
        for (int i = 0; i != nbEtatsSorties; i++)
        {
            monFlux >> nombre;
            INTlisteEtatsSorties.push_back(nombre);
        }

        // Crée tous les états de l'automate
        bool Sortie; bool Entree;
        for (int n = 0; n <= nbEtats; n++)
        {
            // vérifie si l'état est dans INTlisteEtatsEntrées ou INTlisteEtatsSortie
            Entree = verifINTinVECTOR(n, INTlisteEtatsEntrees);
            Sortie = verifINTinVECTOR(n, INTlisteEtatsSorties);
            E = createEtat(n, Entree, Sortie, nbSymboles, nbEtats);
            listeEtats.push_back(E);
            if (Entree)
            {
                listeEtatsEntrees.push_back(E);
            }
            if (Sortie)
            {
                listeEtatsSorties.push_back(E);
            }
        }

        // Recupère le nombre de transitions
        monFlux >> nombre;
        nbTransitions = nombre;

        // Recupère toutes les transitions
        for (int p = 0; p < nbTransitions; p++)
        {
            int cpt = 0;
            vector<string> TEMPligne;
            string TEMPstring;
            // Lit le fichier ligne par ligne
            string mot = "";
            monFlux >> mot;
            // ================== Séquence la ligne afin de de résister si IDEtat >= 10 ==================
            while (isdigit(mot[cpt]))
            {
                TEMPstring += mot[cpt];
                cpt++;
            }
            TEMPligne.push_back(TEMPstring);
            string s(sizeof(char), mot[cpt]);
            TEMPligne.push_back(s);
            cpt++;
            while (isdigit(mot[cpt]))
            {
                TEMPstring = "";
                TEMPstring += mot[cpt];
                cpt++;
            }
            TEMPligne.push_back(TEMPstring);
            // ================== FIN Séquencage ==================

            // Lit les lignes caractère par caractère
            etat *Eentrant = nullptr;
            etat *Esortant = nullptr;
            cpt = 0; int indexSymbole;
            for (auto T: TEMPligne)
            {
                if (cpt == 0)
                {
                    Eentrant = listeEtats[stoi(T)];
                }
                if (cpt == 1)
                {
                    const char *TEMPsymbole = T.data();
                    char symbole = *TEMPsymbole;
                    indexSymbole = indexCHARinVECTOR(symbole, alphabet);
                }
                if (cpt == 2)
                {
                    Esortant = listeEtats[stoi(T)];
                }
                cpt++;
            }
            // Ajout de la transition à l'état
            Eentrant->listeEtatsSortants[indexSymbole][Esortant->etatID] = Esortant;
            Esortant->listeEtatsEntrants[indexSymbole][Eentrant->etatID] = Eentrant;
        }
    }
    else
    {
        cout << "Probleme de fichier txt" << endl;
    }
    automate A = createAutomate(nbTransitions ,nbSymboles, nbEtats, nbEtatsEntrees, nbEtatsSorties, listeEtatsEntrees, listeEtatsSorties, listeEtats);
   
    return A;
}