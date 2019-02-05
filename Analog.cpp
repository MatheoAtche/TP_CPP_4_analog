/*************************************************************************
                           Analog  -  Classe qui teste nos programmes
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include<string>
#include<fstream>
#include<cstring>
//------------------------------------------------------ Include personnel
#include "LectureLog.h"
#include "AnalyseLog.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int main(int argc, char* argv [])
// Algorithme :
//
{
	bool erreur=false;
	bool g;
	bool t;
	bool e;
	int h=0;
	string outFile="";
	if (argc==1)
		cout << "Erreur, pas de fichier '.log' indiqué\n";
	else if (argc==2)
	{
		string fic = argv[1];
		int n=fic.find(".log");
		if (n>0)
		{
			try
			{
				AnalyseLog a (fic);
			}
			catch (const char* message)
			{
				cout << message;
				erreur=true;
			}
		}
		else
		{
			cout<< "Erreur, ce n'est pas un fichier .log\n";
			erreur=true;
		}
	}
	else
	{
	//parcours des options
		for (int i=1; i<argc-1; i++)
		{
			if (strcmp(argv[i],"-g")==0)
			{
				g=true;
				if (i<argc-2)
				{
					outFile = argv[i+1];
				}
				int n=outFile.find(".dot");
				if(outFile=="-e" || outFile=="-t")
				{
					cout << "Erreur, aucun fichier indiqué après l'option -g\n";
					erreur=true;
					break;
				}
				if(n<0)
				{
					cout << "Erreur, Le fichier indiqué suite à l'option -g n'est pas un .dot\n";
					erreur=true;
					break;
				}
				i++;
			}
			else if (strcmp(argv[i],"-t")==0)
			{
				t=true;
				if (i<argc-2)
					h=atoi(argv[i+1]);
				if(h>24 || h<0)
				{
					cout << "Erreur, l'heure n'est pas valide\n";
					erreur=true;
					break;
				}
			}
			else if (strcmp(argv[i],"-e")==0)
			{
				e=true;
				if (i<argc-2 && strcmp(argv[i+1],"-g")!=0 && strcmp(argv[i+1],"-t")!=0)
				{
					cout << "Erreur, des paramètres inutiles ont été détectés\n";
					erreur=true;
				}
			}
			else 
			{
				cout << "Erreur, l'option n'existe pas\n";
				erreur=true;
			}
		}
	}

	//AnalyseLog a("/home/acroc/Documents/TP_CPP_4_analog-master3/anonyme.log",true,false,false,"court.dot");

	return 0;
	
} //----- Fin de main

