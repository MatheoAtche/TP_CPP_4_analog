/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<fstream>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LectureLog.h"

//------------------------------------------------------------- Constantes
const char SEP = ',';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void LectureLog:: LireLigneFichierLog ( ifstream & fic )
// Algorithme :
//
{
	string tmp;
	getline(fic,ligneFichier.ip,' ');
	getline(fic,tmp,'[');
	getline(fic,ligneFichier.date,' ');
	getline(fic,tmp,'"');
	getline(fic,ligneFichier.typeAction,' ');
	getline(fic,ligneFichier.url,' ');
	getline(fic,tmp,'"');
	getline(fic,tmp,'"');
	getline(fic,ligneFichier.referer,'"');
	getline(fic,tmp);
	
	
} //----- Fin de LireLigneFichierLog


//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << ( ostream & os, const LectureLog & lect )
// Algorithme :
//
{
	os<<lect.ligneFichier.ip<<SEP<<lect.ligneFichier.date<<SEP<<lect.ligneFichier.typeAction;
	os<<SEP<<lect.ligneFichier.url<<SEP<<lect.ligneFichier.referer<<endl;
	return os;
     
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
//LectureLog::LectureLog ( const LectureLog & unLectureLog )
// Algorithme :
//
/*{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de LectureLog (constructeur de copie)*/


LectureLog::LectureLog (Ligne l)
// Algorithme :
//
{
	ligneFichier = l;

	#ifdef MAP
	    cout << "Appel au constructeur de <LectureLog>" << endl;
	#endif

	
} //----- Fin de LectureLog


LectureLog::~LectureLog ( )
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de <LectureLog>" << endl;
	#endif
} //----- Fin de ~LectureLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

