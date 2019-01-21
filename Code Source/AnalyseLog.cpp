/*************************************************************************
                           AnalyseLog  -  description
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <AnalyseLog> (fichier AnalyseLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include<set>
//------------------------------------------------------ Include personnel
#include "AnalyseLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 void AnalyseLog::RemplirMap (bool e, bool t,int heure)
// Algorithme :
//
{
	set<string>Suffixe {"php","css","jpg","gif","ico","png","jpeg","ics"};
	
	LectureLog lect;
	bool check=true;; 
	while(!file.eof())
	{
		lect.LireLigneFichierLog();
		if(e)
		{
			//On recupère la position du point
			int pos=lect.ligneFichier.url.find_last_of('.',0);
			string suf;
			if(pos!=-1)
			{	//On recupère la chaine de caracteres qui se trouve après le point
				suf=substr(lect.ligneFichier.url,pos+1);

				if(Suffixe.find(suf)!=Suffixe.end())
				{
					check=false;
				}
			}
			
		}
			
		if(t && check)	
		{
			int h = atoi(substr(lect.ligneFichier.date,12,2));
			if(h!=heure)
			{
				check=false;
			}
		}
		
		if(check)
		{
			
		}
	}
} //----- Fin de RemplirMap


//------------------------------------------------- Surcharge d'opérateurs
//AnalyseLog & AnalyseLog::operator = ( const AnalyseLog & unAnalyseLog )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//AnalyseLog::AnalyseLog ( const AnalyseLog & unAnalyseLog )
// Algorithme :
//
/*{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AnalyseLog>" << endl;
#endif
} *///----- Fin de AnalyseLog (constructeur de copie)


AnalyseLog::AnalyseLog (ifstream & fic,bool g, bool e, bool t, string nomFic,int heure)
// Algorithme :
//
{
	file=fic;
	RemplirMap(e,t,heure);
	#ifdef MAP
	    cout << "Appel au constructeur de <AnalyseLog>" << endl;
	#endif
} //----- Fin de AnalyseLog


AnalyseLog::~AnalyseLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AnalyseLog>" << endl;
#endif
} //----- Fin de ~AnalyseLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

