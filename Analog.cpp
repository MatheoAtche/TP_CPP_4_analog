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

bool checkNumber (char* str)
{
	int t = strlen(str);
	bool check=true;
	for (int i=0; i<t; i++)
	{
		if(!isdigit(str[i]))
		{
			check=false;
		}
	}
	return check;
}

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
	{
		cerr << "Erreur, pas de fichier '.log' indiqué" << endl;
		erreur = true;
		return 1;
	}
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
				cerr << message << endl;
				erreur=true;
				return 1;
			}
		}
		else
		{
			cerr << "Erreur, ce n'est pas un fichier .log" << endl;
			erreur=true;
			return 1;
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
				outFile = argv[i+1];
				int n=outFile.find(".dot");
				if(outFile=="-e" || outFile=="-t" || i==argc-2)
				{
					cerr << "Erreur, aucun fichier indiqué après l'option -g" << endl;
					erreur=true;
					return 1;
				}
				if(n<0)
				{
					cerr << "Erreur, le fichier indiqué suite à l'option -g n'est pas un .dot" << endl;
					erreur=true;
					return 1;
				}
				ifstream fic(outFile.c_str());
				if(fic)
				{
					string choix;
					cout<<"Le fichier existe déjà, le contenu sera écrasé."<<endl;
					cout<<"Voulez-vous continuer? Oui/Non : ";
					cin>>choix;
					cout<<endl;
					while(choix!="Oui" && choix!="Non")
					{	
						cout<<"Voulez-vous continuer? Oui/Non : ";
						cin>>choix;
						cout<<endl;
					}
					if(choix=="Non")
					{
						cerr <<"Fermeture du programme"<<endl;
						erreur=true;
						return 1;
					}
				}
				i++;
			}
			else if (strcmp(argv[i],"-t")==0)
			{
				t=true;
				h=atoi(argv[i+1]);
				if (i>=argc-2 || strcmp(argv[i+1],"-g")==0 || strcmp(argv[i+1],"-e")==0)
				{
					cerr << "Erreur, pas d'heure indiquée après l'option -t" << endl;
					erreur =true;
					return 1;
				}
				if (!checkNumber(argv[i+1]) || h<0 || h>24)
				{
					cerr << "Erreur, indiquez une heure valide après l'option -t" << endl;
					erreur = true;
					return 1;
				}
				i++;
			}
			else if (strcmp(argv[i],"-e")==0)
			{
				e=true;
				if (i<argc-2 && strcmp(argv[i+1],"-g")!=0 && strcmp(argv[i+1],"-t")!=0)
				{
					cerr << "Erreur, des paramètres inutiles ont été détecté" << endl;
					erreur=true;
					return 1;
				}
			}
			else 
			{
				cerr << "Erreur, l'option n'existe pas" << endl;
				erreur=true;
				return 1;
			}
		}
		if(!erreur)
		{
			string fic = argv[argc-1];
			int n=fic.find(".log");
			if (n>0)
			{
				try
				{
					AnalyseLog a (fic, g, e, t, outFile, h);
				}
				catch (const char* message)
				{
					cerr << message << endl;
				}
			}
			else
				cerr << "Erreur, ce n'est pas un fichier .log" << endl;
		}
	}
	return 0;
	
} //----- Fin de main

