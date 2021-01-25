#include <iostream>
#include <conio.h>

using namespace std;

void legende() {
    cout << "==================L=É=G=E=N=D=E==================\n"
            "|o 1 représente les cadres                      |\n"
            "|o 2 représente les travailleurs à tarif horaire|\n"
            "|o 3 représente les travailleurs à commission   |\n"
            "|o 4 représente les travailleurs à la pièce.    |\n"
            "=================================================\n"
            "Insérer le code (-1 pour quitter): " << endl;
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
    //Déclaration et initialisation des variables aux valeurs par défaut.
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
                //Salaire hebdomadaire fixe, sans égard aux heures travaillées;
                cout << "Insérer le salaire hebdomadaire fixe : ";
                cin >> salaireCadre;
                paye += salaireCadre;
                nbrEmployes++;
                break;

            case 2:
                /* Travailleurs à tarif horaire : recevant un taux horaire fixe « régulier » pour
                les 40 premières heures et un taux horaire «temps et demi», soit 1.5 fois le taux horaire
                régulier, pour les heures supplémentaires. (Exercice 2.1)*/
                cout << "Entrez le nombre d'heure travaillé par l’employé(e) (00) : ";
                cin >> heures;
                cout << "Entrez le taux horaire de l’employé(e) ($00.00) : ";
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
                //travailleurs à commission : recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes
                cout << "Entrez le nombre de ventes hebdomadaire(s) : ";
                cin >> salaireCommission;
                paye += 250 + (0.057 * salaireCommission);
                nbrEmployes++;
                break;

            case 4:
                /* travailleur à la pièce : recevant un taux fixe d'argent pour chaque article produit;
                chaque travailleur à la pièce de cette compagnie ne travaille que sur un seul type
                d'article. */
                cout << "Entrez le nombre de ventes d'article de produit(s) : ";
                cin >> pieces;
                cout << "Entrez le pourcentage par produit en décimal (ex. 66.6) : ";
                cin >> salairePiece;
                paye += pieces * salairePiece;
                nbrEmployes++;
                break;

            default:
                if (choixUsager == -1) {
                    cout << "Le salaire total de " << nbrEmployes << " employé(s) est de " << paye << "$";
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
	À effectuer
	Une compagnie rémunère ses employés selon leur fonction :

	* cadres : recevant un salaire hebdomadaire fixe, sans égard aux heures travaillées;

	* travailleurs à tarif horaire :
	recevant un taux horaire fixe « régulier » pour les 40 premières heures
	et un taux horaire «temps et demi», soit 1.5 fois le taux horaire régulier,
	pour les heures supplémentaires;

	* travailleurs à commission :
	recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes;

	* travailleur à la pièce :
	recevant un taux fixe d'argent pour chaque article produit;
	chaque travailleur à la pièce de cette compagnie ne travaille que
	sur un seul type d'article.

	==========================================================================================
	Écrivez un programme qui calcule la paie pour  chaque  employé. Vous ne connaissez pas
	à l'avance le nombre d'employés.

	Utilisez une structure switch pour calculer la paie de chaque employé en fonction du code
	de paie de cet employé. À l'intérieur de cette  structure switch, invitez l'utilisateur
	(par exemple, le responsable de la paie) à entrer les faits appropriés requis par votre
	programme pour calculer la paie de chaque employé en fonction du code de paie de l'employé. */