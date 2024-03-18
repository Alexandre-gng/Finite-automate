#include "automStruct.h"

using namespace std;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x','y', 'z'};

int main() 
{
    automate A = parsing(alphabet);

    printAutomate(A, alphabet);

    printInformationsAutomate(A);

    standardisationAutomate(&A);
    return 0;
}



/*
int choix;
cout << "Afficher l'automate (1)\n" << "Affiher les informations de l'automate (2)\n";
cin >> choix;
if (choix == 1)
{
    printAutomate(A, alphabet);
}
if (choix == 2)
{
    printInformationsAutomate(A);
}
 */