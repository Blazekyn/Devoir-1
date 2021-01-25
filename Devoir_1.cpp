#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	//D�claration et initialisation des variables aux valeurs par d�faut.
	int choixUsager = 0;
	int reponseUsager = 0;
	float pourcentageSalaire = 0.0;
	float salaire = 00.00;

	/*
	 Chaque type d'employ� poss�de son propre code de paie :
	-code de paie 1 repr�sente les cadres;
	-code de paie 2 repr�sente les travailleurs � tarif horaire;
	-code de paie 3 repr�sente les travailleurs � commission; et
	-code de paie 4 repr�sente les travailleurs � la pi�ce.
	*/
	do
	{
		cout << "==================L=�=G=E=N=D=E==================\n"
				"|o 1 repr�sente les cadres                      |\n"
				"|o 2 repr�sente les travailleurs � tarif horaire|\n"
				"|o 3 repr�sente les travailleurs � commission   |\n"
				"|o 4 repr�sente les travailleurs � la pi�ce.    |\n"
				"=================================================\n"
				"Ins�rer le code (-1 pour quitter): " << flush;
		cin >> choixUsager;
		system("CLS");
		switch (choixUsager)
		{
		case -1:
			return 0;
		case 1:
			//Salaire hebdomadaire fixe, sans �gard aux heures travaill�es;
			cout << "Ins�rer le salaire hebdomadaire fixe : ";
			cin >> salaire;
			break;

		case 2:
			/* Travailleurs � tarif horaire : recevant un taux horaire fixe � r�gulier � pour
			les 40 premi�res heures et un taux horaire �temps et demi�, soit 1.5 fois le taux horaire
			r�gulier, pour les heures suppl�mentaires. (Exercice 2.1)*/
			cout << "Entrez le nombre d'heure travaill� par l�employ�(e) (00) : ";
			cout << "Entrez le taux horaire de l�employ�(e) ($00.00) : ";
			cin >> pourcentageSalaire;

			if (reponseUsager <= 40)
			{
				salaire = reponseUsager * pourcentageSalaire;
			}
			else
			{
				salaire = (40.00 * pourcentageSalaire) + ((reponseUsager - 40.00) * (1.5 * pourcentageSalaire));
			}
			break;

		case 3:
			//travailleurs � commission : recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes
			cout << "Entrez le nombre de ventes hebdomadaire(s) : ";
			cin >> reponseUsager;
			salaire = 250 + (0.057 * reponseUsager);
			break;

		case 4:
			/* travailleur � la pi�ce : recevant un taux fixe d'argent pour chaque article produit;
			chaque travailleur � la pi�ce de cette compagnie ne travaille que sur un seul type
			d'article. */
			cout << "Entrez le nombre de ventes d'article de produit(s) : ";
			cin >> reponseUsager;
			cout << "Entrez le pourcentage par produit en d�cimal (ex. 66.6) : ";
			cin >> pourcentageSalaire;
			break;

		default:
			cout << "Entrer un entier entre 1 et 4, alternativement entrer -1 afin de quitter le logiciel.\n" << endl;
			_getch;
			continue;
		}
		/*Reinitilisation de la varibale reponseUsager afin de conformer la variable au contexte n�cessaire,
		1 �tant un employ�*/
		reponseUsager = 1;
		cout << "Pour combien de employ�s calculer-vous le salaire (1 pour individuel): ";
		cin >> reponseUsager;
		cout << "Le salaire de " << reponseUsager << " employ�(s) est de " << (salaire * reponseUsager) << "$";
	} while (true);
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