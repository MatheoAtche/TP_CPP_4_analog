/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include<string>
#include<fstream>
//------------------------------------------------------ Include personnel
#include "LectureLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 int main(int argc, char* argv [])
// Algorithme :
//
{
	ifstream file("/tmp/anonyme.log");

	LectureLog lec;
	lec.LireLigneFichierLog(file);
	cout<<lec;
	return 0;
	
} //----- Fin de main




