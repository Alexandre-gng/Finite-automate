#include "automStruct.h"

using namespace std;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x','y', 'z'};

int main() 
{
    cout << "LANCEMENT PROGRAMME" << endl;
    automate A = parsing(alphabet);
    printAutomate(A, alphabet);
    printInformationsAutomate(A, alphabet);


    automate* AStandard = standardisationAutomate(&A);
    printAutomate(*AStandard, alphabet);
    printInformationsAutomate(*AStandard, alphabet);


    automate* AComplet = completionAutomate(AStandard);
    printAutomate(*AComplet, alphabet);
    printInformationsAutomate(*AComplet, alphabet);

    printAutomate(A, alphabet);

    return 0;
}



/*
int choix;
cout << "Afficher l'automate (1)\n" << "Afficher les informations de l'automate (2)\n" << "Tester la reconnaissance d'un mot (3)\n";
cin >> choix;
if (choix == 1)
{
    printAutomate(A, alphabet);
}
if (choix == 2)
{
    printInformationsAutomate(A);
}
if (choix == 3)
{
    
}

 */
