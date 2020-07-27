/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Tree.h"
#include "catch.h"

using namespace std;

	///////////////////////////////////////
	// Hilfsmethoden fürs Menü hier:



	//
	///////////////////////////////////////
	int main() {

		int result = Catch::Session().run();
		
		/*Tree * nTree = new Tree();
		nTree->addNode("Mayer", 20, 0, 0);
		nTree->addNode("Mayer2", 10, 0, 0);
		nTree->addNode("Mayer3", 30, 0, 0);
		nTree->addNode("Mayer4", 5, 0, 0);
		nTree->addNode("Mayer5", 2, 0, 0);

		nTree->printAll();
		nTree->rotateTreeRight(get_anker(*nTree)->getLeft(), get_anker(*nTree)->getLeft()->getLeft());
		nTree->printAll();*/
		
		///////////////////////////////////////
		// Ihr Code hier:
		Tree neuer_eintrag;
		int wahl = 0;
		do
		{
			int posID = 0, alter = 0, plz = 0;
			char importieren = 'n';
			cout << "\n====================================\n1) Datensatz einfuegen, manuell\n2) Datensatz einfuegen, CSV Datei\n3) Datensatz loeschen\n4) Suchen\n5) Ausgabe in Preorder\n6) Ausgabe in Levelorder\n?>";
			cin >> wahl;
			cin.ignore();
			cout << endl;
			double  einkommen = 0.0;
			string gesucht = "", name = "";
			if (wahl == 1)
			{
				cout << "Bitte geben Sie die den Datensatz ein\n";
				cout << "Name ?>";
				getline(cin, name);
				cout << "Alter ?>";
				cin >> alter;
				cout << "Einkommen ?>";
				cin >> einkommen;
				cout << "PLZ ?>";
				cin >> plz;
				neuer_eintrag.addNode(name, alter, einkommen, plz);
				cout << "Ihr Datensatz wurde eingefuegt" << endl;
			}
			else if (wahl == 2)
			{
				cout << "Moechten Sie die Daten aus der Datei 'ExportZielanalyse.csv' importieren (j/n) ?>";
				cin >> importieren;
				cin.ignore();
				if (importieren == 'j')
				{
					ifstream csvread;
					csvread.open("ExportZielanalyse.csv", ios::in);
					if (csvread) {
						//Datei bis Ende einlesen und bei ';' strings trennen
						string Name = "", Alter = "", Einkommen = "", PLZ = "";
						int _Alter = 0, _PLZ = 0;
						double _Einkommen = 0.0;
						while (!csvread.eof())
						{
							getline(csvread, Name, ';');
							getline(csvread, Alter, ';');
							getline(csvread, Einkommen, ';');
							getline(csvread, PLZ, '\n');
							_Alter = stoi(Alter);
							_Einkommen = stod(Einkommen);
							_PLZ = stoi(PLZ);
							if (!csvread || Name == "")
							{
								break;
							}
							neuer_eintrag.addNode(Name, _Alter, _Einkommen, _PLZ);
						}
						csvread.close();
					}
					else {
						cerr << "Fehler beim Lesen!" << endl;
					}

					cout << "Daten wurden dem Baum hinzugefuegt.\n";
				}
				else
				{
					cout << "Importieren wurde abgebrochen.\n";
				}
			}
			else if (wahl == 3)
			{
				cout << "Bitte geben Sie den zu loschenden Datensatz an";
				cout << "PosID ?> ";
				cin >> posID;
				cout << "Datensatz wurde geloescht.\n";

			}
			else if (wahl == 4)
			{
				cout << "Bitte geben Sie den zu suchenden Datensatz an";
				cout << "Name ?> ";
				getline(cin, gesucht);
				neuer_eintrag.searchNode(gesucht);
			}
			else if (wahl == 5)
			{
				neuer_eintrag.printAll();
			}
			else if (wahl == 6)
			{
				cout << "Ausgabe in Levelorder:\n";
				neuer_eintrag.printLevelOrder();
			}
		} while (wahl != 6);
		//
		///////////////////////////////////////
		system("PAUSE");

		return 0;
	}
