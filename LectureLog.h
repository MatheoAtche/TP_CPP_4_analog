/*************************************************************************
                           LectureLog  -  Classe lisant une ligne d'un fichier
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
//---------- Interface de la classe <LectureLog> (fichier LectureLog.h) ----------------
#if ! defined ( LECTURELOG_H )
#define LECTURELOG_H

//--------------------------------------------------- Interfaces utilisées
#include<string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct Ligne
{
	string ip;
	string date;
	string typeAction;
	string url;
	string referer;
	Ligne(string i = "", string d = "", string ta = "", string u = "", string r = "")
		:ip(i), date(d), typeAction(ta), url(u), referer(r)
	{}
};

//------------------------------------------------------------------------
// Rôle de la classe <LectureLog>
//Cette classe permet de lire la ligne courante d'un fichier log Apache et
//d'affecter à son attribut les caractéristiques de cette ligne qui sont
//l'ip, la date et l'heure de la requête, le type d'action excutée,
//l'url du document demandé et le referer
//
//------------------------------------------------------------------------


class LectureLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    friend ostream & operator <<(ostream & os,const LectureLog & lect);
	// Mode d'emploi : Déclaration de la fonction non-membre operator <<
	//amie de la classe LectureLog
	//Paramètres:
	//		-os est une référence à un flux de sortie pour afficher l'objet lect
	//		-lect est l'objet que l'on souhaite affiché
	// Contrat : aucun

    friend class AnalyseLog;
	// Mode d'emploi : Déclaration de la classe AnalyseLog amie de la classe LectureLog
	// Contrat : aucun

    void LireLigneFichierLog ( ifstream & fic );
    // Mode d'emploi : Lire la ligne courante du fichier fic 
    //et récupérer ses caractéristiques
	//Paramètre : 
	//		-fic est le nom du fichier que l'on veut lire
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //LectureLog & operator = ( const LectureLog & unLectureLog );
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
    // Mode d'emploi : Contruit un LectureLog
	//Paramètres : 
	//		-l est un élément de la structure Ligne pour initialiser l'attribut ligneFichier
    // Contrat : aucun
   

    virtual ~LectureLog ( );
    // Mode d'emploi : Détruit un LectureLog
    //Paramètres : aucun
    // Contrat : aucun
  

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	//Les caractéristiques d'un eligne d'un fichier
    Ligne ligneFichier; 

};

//-------------------------------- Autres définitions dépendantes de <LectureLog>

#endif // LECTURELOG_H

