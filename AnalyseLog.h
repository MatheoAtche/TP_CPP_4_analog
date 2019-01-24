/*************************************************************************
                           AnalyseLog  -  description
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AnalyseLog> (fichier AnalyseLog.h) ----------------
#if ! defined ( ANALYSELOG_H )
#define ANALYSELOG_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include<fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AnalyseLog>
//
//
//------------------------------------------------------------------------

class AnalyseLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void RemplirMap (bool e, bool t,int heure);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //AnalyseLog & operator = ( const AnalyseLog & unAnalyseLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //AnalyseLog ( const AnalyseLog & unAnalyseLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AnalyseLog (ifstream & fic, bool g, bool e, bool t, string nomFic,int heure);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AnalyseLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	ifstream file;
	typedef map<string,pair<map<string,int>,int> StructGraphe;
	StructGraphe graphe;
};

//-------------------------------- Autres définitions dépendantes de <AnalyseLog>

#endif // ANALYSELOG_H

