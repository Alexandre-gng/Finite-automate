#include "automStruct.h"

using namespace std;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x','y', 'z'};

int main()
{
    cout << "LANCEMENT PROGRAMME" << endl;
    automate A = parsing(alphabet);
    printAutomate(A, alphabet);
    printInformationsAutomate(A, alphabet);
    /*
    automate AStandard = standardisationAutomate(&A);
    printAutomate(AStandard, alphabet);
    printInformationsAutomate(AStandard, alphabet);
    */

    /*
    automate AComplet = completionAutomate(&A);
    printAutomate(AComplet, alphabet);
    printInformationsAutomate(AComplet, alphabet);
    */
    
    automate ADeter = determinisationAutomate(&A);
    printAutomate(ADeter, alphabet);
    printInformationsAutomate(ADeter, alphabet);
    
    /*
    cout << "COMPLEMENT = " << endl;
    automate Acomplement = complementAutomate(&A);
    printAutomate(Acomplement, alphabet);
    printInformationsAutomate(Acomplement, alphabet);
    */
    /*
    vector<string> LISTEmot = { "abbbaa", "a", "abaa" };
    vector<bool> RES = testReconnaissanceMot(A, LISTEmot);
    for (int i = 0; i < LISTEmot.size(); i++)
    {
        cout << "LISTEmot[i] = " << LISTEmot[i] << " | and res = " << RES[i] << endl;
    }
    */
    return 0;

}



/*
    int choix;
    int nbreMots;
    vector<string> LISTEmot;
    cout << "\n\nAfficher l'automate (1)\n" << "Afficher les informations de l'automate (2)\n" << "Tester la reconnaissance d'un mot (3)\n";
    cin >> choix;
    if (choix == 1)
    {
        printAutomate(A, alphabet);
    }
    if (choix == 2)
    {
        printInformationsAutomate(A, alphabet);
    }
    if (choix == 3)
    {
        cout << "Combien de mots souhaitez-vous tester: ";
        cin >> nbreMots;
        for (int i = 0; i < nbreMots; i++)
        {
            cout << "Saisissez le mot: ";
            cin >> LISTEmot[i];
        }
        testReconnaissanceMot(A, LISTEmot);
    }
 */
