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
	bool bg;
	bool bt;
	bool be;
	int g;
	int t;
	int e;
	if (argc==1)
		cout << "Erreur, pas de fichier '.log' indiqué\n";
	else if (argc==2)
	{
		string fic = argv[1];
		if (fic.substr(fic.find_last_of('.'))==".log")
		{
			AnalyseLog a (fic);
		}
		else
		{
			"Erreur, ce n'est pas un fichier .log\n";
		}
	}
	else
	{
	//parcours des options
		for (int i=1; i<argc-1; i++)
		{
			if (strcmp(argv[i],"-g")==0)
			{
				bg=true;
				g=i;
				if (i<argc-1)
				{
					string outFile = argv[i+1];
				}
				else
					cout << "Erreur, pas de fichier .dot indiqué\n";
			}
			if (strcmp(argv[i],"-t")==0)
			{
				bt=true;
				t=i;
			}
			if (strcmp(argv[i],"-e")==0)
			{
				be=true;
				e=i;
			}
		}
	}

	return 0;
	
} //----- Fin de main




