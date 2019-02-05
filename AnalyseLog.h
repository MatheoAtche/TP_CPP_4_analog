/*************************************************************************
                           AnalyseLog  -  Classe qui analyse le fichier log Apache
                             -------------------
    début                : 21/01/2019
    copyright            : (C) Mathéo ATCHE et Andréa CROC
    e-mail               : matheo.atche@insa-lyon.fr et andrea.croc@insa-lyon.fr
*************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <AnalyseLog> (fichier AnalyseLog.h) ----------------
#if ! defined ( ANALYSELOG_H )
#define ANALYSELOG_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include<fstream>
#include<iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AnalyseLog>
//Cette classe fait plusieurs opérations à partir d'un fichier log Apache
//
//Elle est caractérisée par le fichier qu'on veut analyser, et une structure
//map de map contenant les caractéristiques de chaque ligne du fichier

//Cette classe permet de lire et d'analyser tout un fichier log Apache
//en remplissant sa map, d'afficher les 10 documents les plus consultés
//et de générer un graphe
//------------------------------------------------------------------------

class AnalyseLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void RemplirMap (bool e, bool t, int heure);
    // Mode d'emploi : Remplir la structure map 
    //en lisant le fichier ligne par ligne 
	//selon les options d'exécution
	//Paramètres : 
	//		-e : contient true si l'option de séléction des documents
	//suivant leur extension a été écrite à l'exécution
	//		-t : contient true si l'option de sélection de l'heure de la requête 
	//est écrit à l'exécution 
	//		-heure : correspond à l'heure à laquelle doit être fait la requête
	//si l'option t est mise
    // Contrat : aucun
   

	void GenererGraphe(bool g,string nomFichier);
	// Mode d'emploi : Ecrire dans un fichier .dot pour générer
	// un graphe représentant les requetes entre url et referer
	//Paramètres : 
	//		-g : contient true si l'option pour faire le graphe est mise à l'exécution
	//		-nomFichier : est le nom du fichier .dot dans lequel on décrit le graphe
	// Contrat : aucun

	void AfficherTop10(ostream & os = cout);
	// Mode d'emploi : Afficher les 10 documents les plus consultés
	//par ordre décroissant de popularités
	//Paramètres : 
	//		-os correspond au flux de sortie dans lequel on
	//veut afficher la liste des 10 documents
	// Contrat : aucun
	

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

    AnalyseLog (ifstream & fic, bool g=false, bool e=false, bool t=false, string nomFic="",int heure=0);
    // Mode d'emploi : Construit un AnalyseLog en remplissant la map suivant
    //les options en appelant la méthode RemplirMap
	//Paramètres : 
	//		-fic est le fichier log Apache que l'on veut analyser
	//		-g vaut true si cette option de générer un graphe a été mise à l'exécution
	//		-e : contient true si l'option de séléction des documents
	//suivant leur extension a été écrite à l'exécution
	//		-t : contient true si l'option de sélection de l'heure de la requête 
	//est écrit à l'exécution 
	//		-nomFic est le nom du fichier dans lequel on veut générer le graphe
	//		-heure : correspond à l'heure à laquelle doit être fait la requête
	//si l'option t est mise
    // Contrat : aucun

    virtual ~AnalyseLog ( );
    // Mode d'emploi : Détruit un AnalyseLog
    // Contrat : aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	//Fichier log Apache que l'on souhaite analyser
	ifstream file;
	typedef map<string,pair<map<string,int>,int>> StructGraphe;
	//Structure map contenant le nom de chaque url et une paire associée
	//composée d'une map contenant tous les referers et le nombre de fois
	//qu'une requête a été faite de ce referer vers cet url, et d'un entier
	//qui correspond au nombre total de fois qu'une requête a été faite vers cet url
	StructGraphe graphe;
};

//-------------------------------- Autres définitions dépendantes de <AnalyseLog>

#endif // ANALYSELOG_H

