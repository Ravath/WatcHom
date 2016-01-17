#ifndef CONTROLLEUR_HPP
#define CONTROLLEUR_HPP

#include <memory>
#include "Data\Obj.hpp"

class Controlleur
{
public:
	~Controlleur();
	typedef std::shared_ptr<Controlleur> Ptr;
	//fonction de singleton et d'acc�s au bidule
	static Ptr get();
	//fonction de rafraichissement utilis�e par la fenetre d'affichage
	void drawGL();	//g�re les autres fonctions de dessin en fonction du contexte

	//fonctions de chargement
	void loadObj(std::string path);//charge un obj et le sauvegarde ds objAffiche pour l'afficher
private:
	Controlleur();

	obj::Obj::Ptr objAffiche;	//l'objet � afficher
	obj::Vertex center;			//le centre du rep�re d'affichage. Pas encore utilis�

	//fonctions de dessin
	void drawDefault();
	void drawObj();
	void drawCube0(obj::Vertex center);
	void drawCube1(std::vector<obj::Vertex> line);
	void drawFace(const obj::Object::face &fa);
};

#endif