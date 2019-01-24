/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LectureLog> (fichier LectureLog.h) ----------------
#if ! defined ( LECTURELOG_H )
#define LECTURELOG_H

//--------------------------------------------------- Interfaces utilisées
#include<string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LectureLog>
//
//
//------------------------------------------------------------------------
struct Ligne
{
	string ip;
	string date;
	string typeAction;
	string url;
	string referer;
	Ligne(string i="", string d="", string ta="", string u="",string r="")
		:ip(i),date(d),typeAction(ta),url(u),referer(r)
	{}
};

class AnalyseLog;

class LectureLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    friend ostream & operator <<(ostream & os,const LectureLog & lect);
    friend class AnalyseLog;

    void LireLigneFichierLog ( ifstream & fic );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //LectureLog & operator << ( const LectureLog & unLectureLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //LectureLog ( const LectureLog & unLectureLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LectureLog ( Ligne l = Ligne());
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LectureLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Ligne ligneFichier; 

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LECTURELOG_H

