/*************************************************************************
                           AnalyseLog  -  Classe qui analyse le fichier log Apache
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
#include<string>
//------------------------------------------------------ Include personnel
#include "AnalyseLog.h"
#include "LectureLog.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 void AnalyseLog::RemplirMap (bool e, bool t,int heure)
// Algorithme : Remplit la map de la classe AnalyseLog
//selon les options d'exécution e (extension document),
//t (heure requête) 
{
	// Conteneur Suffixe contenant la liste des suffixes que l'on 
	//ne souhaite pas si l'option e est true
	set<string>Suffixe {"php","css","jpg","gif","ico","png","jpeg","ics"};
	
	LectureLog lect; 
	while(!file.eof())
	{
		bool check=true;
		lect.LireLigneFichierLog(file);
		if(e)
		{
			//On recupère la position du point
			int pos=lect.ligneFichier.url.find_last_of('.',0);
			string suf;
			if(pos!=-1)
			{	//On recupère la chaine de caracteres qui se trouve après le point
				suf = lect.ligneFichier.url.substr(pos + 1);

				//Si l'extension du document est dans Suffixe
				if(Suffixe.find(suf)!=Suffixe.end())
				{
					check=false;
				}
			}
			
		}
			
		if(t && check)	
		{
			int h = atoi(lect.ligneFichier.date.substr(12, 2).c_str());
			//Si l'heure de la requête ne correspond pas à celle attendue
			if(h!=heure)
			{
				check=false;
			}
		}
		
		if(check)
		{
			//Si l'url de la ligne lu n'est pas present dans le graphe
			if (graphe.find(lect.ligneFichier.url) == graphe.end())
			{
				//On crée une map avec le referer et 1 car c'est la première fois 
				//qu'on trouve l'url et donc le referer vers cet url
				map<string, int> reference;
				reference.insert(make_pair(lect.ligneFichier.referer, 1));
				
				//On cree une paire avec la map precedente et le nombre total de reference a l'url
				//qui est pour le moment de 1
				pair<map<string, int>, int> pref(reference, 1);

				//On insère la paire dans le graphe
				graphe.insert(make_pair(lect.ligneFichier.url,pref));
				
			}
			//Si l'url de la ligne lu est déja présent dans le graphe
			else
			{
				StructGraphe::iterator itRef;
				itRef = graphe.lower_bound(lect.ligneFichier.url);


				//Si le referer de la ligne lu est déja présent dans la map de l'url du graphe
				if (itRef->second.first.find(lect.ligneFichier.referer) != itRef->second.first.end())
				{
					map<string, int>::iterator itNb;
					itNb = itRef->second.first.lower_bound(lect.ligneFichier.referer);

					//On incrémente le nombre de fois qu'on a fait 
					//la requete depuis ce referer vers l'url
					itNb->second = itNb->second + 1;

					//On incrémente le nombre total de fois qu'on a fait une requete vers cet url
					itRef->second.second = itRef->second.second + 1;
				}
				//Si le referer de la ligne lu n'est pas présent dans la map de l'url du graphe
				else
				{
					//On insère le referer et 1 car c'est la premiere fois 
					//qu'on trouve une requête depuis ce referer vers l'url
					itRef->second.first.insert(make_pair(lect.ligneFichier.referer, 1));

					//On incrémente le nombre total de fois qu'on a fait une requete vers cet url
					itRef->second.second = itRef->second.second + 1;
				}
			}
		}
	}
} //----- Fin de RemplirMap

 void AnalyseLog::GenererGraphe(bool g, string nomFichier)
// Algorithme : Génerer un fichier .dot en écrivant dedans
// la description textuelle du graphe avec comme noeud les
// url et referer et des arcs représentant les liens entre
//les referers et les url avec le nombre de hits sur les arcs
 {
	 if (g)
	 {
		 //Tester si ouverture fichier ok
		 ofstream fichier(nomFichier.c_str());
		 fichier << "digraph {" << endl;

		 //Itérateurs sur le debut et la fin de la map de map
		 StructGraphe::const_iterator debutG, finG;
		 debutG = graphe.begin();
		 finG = graphe.end();

		 //Itérateurs sur le début et la fin de la map avec referer et hit
		 map<string, int>::const_iterator debR,finR;

		 //Map contenant le nom de l'url ou referer et le numéro du noeud
		 map<string,int>node;

		 //Numéro des noeuds		
		 int compteur=0;

		 while (debutG != finG)
		 {
			 debR = debutG->second.first.begin();
			 finR = debutG->second.first.end();
			 
			 //Si l'url n'est pas déjà un noeud
			 if (node.find(debutG->first) == node.end())
			 {
				 //On représente les noeuds
				 fichier << "node" <<compteur<<" [label=\""<<debutG->first << "\"];" << endl;
				 node.insert(make_pair(debutG->first,compteur);
				 compteur++;
			 }

			 while (debR != finR)
			 {
				 //Si le referer n'est pas déjà un noeud
				 if (node.find(debR->first)==node.end())
				 {
					 //On représente les noeuds
					 fichier << "node" <<compteur<<" [label=\""<<debR->first << "\"];" << endl;
					 node.insert(make_pair(debR->first,compteur);
					 compteur++;
				 }
				 debR++;
			 }
			 
			 debutG++;
		 }

		 //On remet l'itérateur au début
		 debutG = graphe.begin();

		 while (debutG != finG)
		 {
			 debR = debutG->second.first.begin();
			 finR = debutG->second.first.end();

			 while (debR != finR)
			 {
				 //On décrit les liens entre url et referer
				 //fichier << "      " <<debR->first << " -> " << debutG->first << " [label=\"" << debR->second << "\"];" << endl;
				 fichier<<"node"<<node.find(debR->first).second<<" -> "<<"node"<<node.find(debutG->first).second<<" [label=\""<<debR->second<<"\"];" << endl;
				 debR++;
			 }

			 debutG++;
		 }

		 fichier << "}" << endl;
	 }

 }//----- Fin de GenererGraphe

 void AnalyseLog ::AfficherTop10(ostream & os)
 {
	 StructGraphe::const_iterator debut, fin;
	 fin = graphe.end();

	 set<string>listeMax;

	 //On cherche le top 10
	 for (int i = 0; i < 10; i++)
	 {
		 debut = graphe.begin();
		 
		 bool existe = false;
		 int hitmax = 0;
		 string url="";
		 while (debut != fin)
		 {
			 //Si le nombre total de réferences à l'url est supérieur au max
			 //et l'url n'a pas déjà été affiché
			 if (debut->second.second > hitmax && listeMax.find(debut->first) == listeMax.end())
			 {
				 hitmax = debut->second.second;
				 url = debut->first;
				 existe = true;
			 }
			 debut++;
		 }
		 //Pour sortir de la boucle si il y a moins de 10 documents dans la map
		 if (!existe)
		 {
			 break;
		 }

		 os << url << " (" << hitmax << " hits)"<<endl;
		 listeMax.insert(url);
	 }

 }

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
	//GenererGraphe(g, nomFic);
	AfficherTop10();

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

