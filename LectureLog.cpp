/*************************************************************************
                           LectureLog  -  Classe lisant une ligne d'un fichier
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
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
//On récupère les informations de la ligne courante du fichier
//donné en paramètre pour les mettre dans l'objet LectureLog
//qui a appelé cette méthode
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
//On affiche sur le flux de sortie les attributs d'un objet LectureLog
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
//Initialiser l'attribut d'un objet LectureLog
{
	ligneFichier = l;

	#ifdef MAP
	    cout << "Appel au constructeur de <LectureLog>" << endl;
	#endif

	
} //----- Fin de LectureLog


LectureLog::~LectureLog ( )
// Algorithme :
//Rien à préciser
{
	#ifdef MAP
	    cout << "Appel au destructeur de <LectureLog>" << endl;
	#endif
} //----- Fin de ~LectureLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

