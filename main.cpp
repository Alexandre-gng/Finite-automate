#include "automStruct.h"

using namespace std;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x','y', 'z'};
string pathFile;

automate initAutomate()
{
    int choix = 0;
    pathFile = "C:/Users/alexa/CLionProjects/Automate/automates/C3-";
    cout << "\nQuelle automate souhaitez-vous utiliser: ";
    cin >> choix;
    pathFile += to_string(choix) + ".txt";
    automate A = parsing(alphabet, pathFile);
    return A;
}


int main()
{
    int choix = 0;
    int nbreMots;

    automate A = initAutomate();
    cout << "\n\n(1) Afficher l'automate\n" << "(2) Afficher les informations de l'automate\n" << "(3) Tester la reconnaissance d'un mot \n" << "(4) Standardiser l'automate \n"
    << "(5) Determiniser et Completer l'automate\n" << "(6) Obtenir l'automate du langage complementaire\n" << "(70) Changer d'automate\n"
    << "(99) Quitter le programme\n";
    cin >> choix;

    while(choix != 99) {

        // Affichage automate
        if (choix == 1) {
            printAutomate(A, alphabet);
        }
        // Affichage informations
        if (choix == 2) {
            printInformationsAutomate(A, alphabet);
        }
        // Test liste de mots
        if (choix == 3) {
            cout << "Combien de mots souhaitez-vous tester: ";
            cin >> nbreMots;
            vector<string> LISTEmot(nbreMots);
            for (int i = 0; i < nbreMots; i++) {
                cout << "Saisissez le mot " << i + 1 << " : ";
                cin >> LISTEmot[i];
            }
            vector<bool> RESRECO(nbreMots);
            RESRECO = testReconnaissanceListeMots(A, LISTEmot);

            for (int i = 0; i<nbreMots; i++)
            {
                cout << " MOT #" << i + 1  << " = " << RESRECO[i] << endl;
            }
        }
        // Obtention automate standardisé
        if (choix == 4) {
            int RESSTAND = stoi(checkStandard(A, alphabet)[0]);
            if (!RESSTAND)
            {
                A = standardisationAutomate(&A);
                printAutomate(A, alphabet);
            }
            else
            {
                cout << "L'automate est deja standardise" << endl;
            }
        }
        // Obtention automate déterministe
        if (choix == 5)
        {
            int RESDETER = stoi(checkDeterministe(A, alphabet)[0]);
            int RESCOMPL = stoi(checkComplet(A, alphabet)[0]);
            if (RESDETER) {
                if (RESCOMPL)
                {
                    printAutomate(A, alphabet);
                }
                else
                {
                    A = completionAutomate(&A);
                    printAutomate(A, alphabet);
                }
            }
            else
            {
                A = determinisationAutomate(&A);
                RESCOMPL = stoi(checkComplet(A, alphabet)[0]);
                if (!RESCOMPL)
                {
                    A = completionAutomate(&A);
                }
                printAutomate(A, alphabet);
            }
        }
        // Obtention automate langage complémentaire équivalent
        if (choix == 6) {
            int RESDETER = stoi(checkDeterministe(A, alphabet)[0]);
            int RESCOMPL = stoi(checkComplet(A, alphabet)[0]);
            if (RESDETER) {
                if (RESCOMPL)
                {
                    A = complementAutomate(&A);
                    printAutomate(A, alphabet);
                }
                else
                {
                    A = completionAutomate(&A);
                    A = complementAutomate(&A);
                    printAutomate(A, alphabet);
                }
            }
            else
            {
                A = determinisationAutomate(&A);
                RESCOMPL = stoi(checkComplet(A, alphabet)[0]);
                if (!RESCOMPL)
                {
                    A = completionAutomate(&A);
                }
                A = complementAutomate(&A);
                printAutomate(A, alphabet);
            }
        }
        // Changement d'automate
        if (choix == 70)
        {
            freeAutomate(&A);
            automate A = initAutomate();
        }
        // Quitter programme
        if (choix == 99)
        {
            cout << "Fin du programme" << endl;
            return 0;
        }
        cout << "\n\n(1) Afficher l'automate\n" << "(2) Afficher les informations de l'automate\n" << "(3) Tester la reconnaissance d'un mot \n" << "(4) Standardiser l'automate \n"
             << "(5) Determiniser et Completer l'automate\n" << "(6) Obtenir l'automate du langage complementaire\n" << "(70) Changer d'automate\n"
             << "(99) Quitter le programme\n";
        cin >> choix;
    }
    return 0;
}



/*
int main()
{
    automate A = initAutomate();
    int nbreMots;

    cout << "Combien de mots souhaitez-vous tester: ";
    cin >> nbreMots;
    vector<string> LISTEmot(nbreMots);
    for (int i = 0; i < nbreMots; i++) {
        cout << "Saisissez le mot " << i + 1 << " : ";
        cin >> LISTEmot[i];
    }
    vector<bool> RESRECO(nbreMots);
    RESRECO = testReconnaissanceListeMots(A, LISTEmot);

    for (int i = 0; i<nbreMots; i++)
    {
        cout << " MOT #" << i + 1  << " = " << RESRECO[i] << endl;
    }
}
*/


/*
    cout << "\n\n";
    for (int i = 0; i < A.nbEtats; i++) {
        for (int s = 0; s < A.nbSymboles; s++) {
            for (int j = 0; j < A.nbEtats; j++) {
                if (A.listeEtats[i]->listeEtatsSortants[s][j] != NULL)
                    cout << "A.listeEtats["<< i << "]->listeEtatsSortants[" << s << "][" << j << "] = " << A.listeEtats[i]->listeEtatsSortants[s][j]->etatID << endl;
            }
        }
    }
    cout << "\n\n";
    cout << "A->listeEtats[1]->listeEtatsSortants[0][2]->name = " << A.listeEtats[1]->listeEtatsSortants[0][2]->name << endl;

 */
