#include <iostream>
#include <conio.h>

using namespace std;

void legende() {
    cout << "==================L=�=G=E=N=D=E==================\n"
            "|o 1 repr�sente les cadres                      |\n"
            "|o 2 repr�sente les travailleurs � tarif horaire|\n"
            "|o 3 repr�sente les travailleurs � commission   |\n"
            "|o 4 repr�sente les travailleurs � la pi�ce.    |\n"
            "=================================================\n"
            "Ins�rer le code (-1 pour quitter): " << endl;
}

int inputPrompt() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cout << "\nErreur dans la saisie. (1,2,3,4) ou -1 pour quitter" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        legende();
        cin >> input;
    }
    return input;
}


int main() {
    //D�claration et initialisation des variables aux valeurs par d�faut.
    int choixUsager;
    int pieces;
    int nbrEmployes = 0;

    double salaireCadre, salaireHoraire, salaireCommission, salairePiece;
    double paye = 0, heures;

    do {
        legende();
        choixUsager = inputPrompt();

        switch (choixUsager) {
            case 1:
                //Salaire hebdomadaire fixe, sans �gard aux heures travaill�es;
                cout << "Ins�rer le salaire hebdomadaire fixe : ";
                cin >> salaireCadre;
                paye += salaireCadre;
                nbrEmployes++;
                break;

            case 2:
                /* Travailleurs � tarif horaire : recevant un taux horaire fixe � r�gulier � pour
                les 40 premi�res heures et un taux horaire �temps et demi�, soit 1.5 fois le taux horaire
                r�gulier, pour les heures suppl�mentaires. (Exercice 2.1)*/
                cout << "Entrez le nombre d'heure travaill� par l�employ�(e) (00) : ";
                cin >> heures;
                cout << "Entrez le taux horaire de l�employ�(e) ($00.00) : ";
                cin >> salaireHoraire;

                if (heures <= 40) {
                    paye += salaireHoraire * heures;
                    nbrEmployes++;
                } else {
                    paye += (40.00 * salaireHoraire) + ((heures - 40.00) * (1.5 * salaireHoraire));
                    nbrEmployes++;
                }
                break;

            case 3:
                //travailleurs � commission : recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes
                cout << "Entrez le nombre de ventes hebdomadaire(s) : ";
                cin >> salaireCommission;
                paye += 250 + (0.057 * salaireCommission);
                nbrEmployes++;
                break;

            case 4:
                /* travailleur � la pi�ce : recevant un taux fixe d'argent pour chaque article produit;
                chaque travailleur � la pi�ce de cette compagnie ne travaille que sur un seul type
                d'article. */
                cout << "Entrez le nombre de ventes d'article de produit(s) : ";
                cin >> pieces;
                cout << "Entrez le pourcentage par produit en d�cimal (ex. 66.6) : ";
                cin >> salairePiece;
                paye += pieces * salairePiece;
                nbrEmployes++;
                break;

            default:
                if (choixUsager == -1) {
                    cout << "Le salaire total de " << nbrEmployes << " employ�(s) est de " << paye << "$";
                    break;
                } else {
                    cout << "Entrer un entier entre 1 et 4, alternativement entrer -1 afin de quitter le logiciel.\n";
                    break;
                }
        }

    } while (choixUsager != -1);

    return 0;
}
/*	==========================================================================================
	||									INSTRUCTIONS										||
	==========================================================================================
	� effectuer
	Une compagnie r�mun�re ses employ�s selon leur fonction :

	* cadres : recevant un salaire hebdomadaire fixe, sans �gard aux heures travaill�es;

	* travailleurs � tarif horaire :
	recevant un taux horaire fixe � r�gulier � pour les 40 premi�res heures
	et un taux horaire �temps et demi�, soit 1.5 fois le taux horaire r�gulier,
	pour les heures suppl�mentaires;

	* travailleurs � commission :
	recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes;

	* travailleur � la pi�ce :
	recevant un taux fixe d'argent pour chaque article produit;
	chaque travailleur � la pi�ce de cette compagnie ne travaille que
	sur un seul type d'article.

	==========================================================================================
	�crivez un programme qui calcule la paie pour  chaque  employ�. Vous ne connaissez pas
	� l'avance le nombre d'employ�s.

	Utilisez une structure switch pour calculer la paie de chaque employ� en fonction du code
	de paie de cet employ�. � l'int�rieur de cette  structure switch, invitez l'utilisateur
	(par exemple, le responsable de la paie) � entrer les faits appropri�s requis par votre
	programme pour calculer la paie de chaque employ� en fonction du code de paie de l'employ�. */