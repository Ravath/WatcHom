#ifndef CONTROLLEUR_HPP
#define CONTROLLEUR_HPP

#include <memory>
#include "Data\Obj.hpp"

class Controlleur
{
public:
	~Controlleur();
	typedef std::shared_ptr<Controlleur> Ptr;
	//fonction de singleton et d'accès au bidule
	static Ptr get();
	//fonction de rafraichissement utilisée par la fenetre d'affichage
	void drawGL();	//gère les autres fonctions de dessin en fonction du contexte

	//fonctions de chargement
	void loadObj(std::string path);//charge un obj et le sauvegarde ds objAffiche pour l'afficher
private:
	Controlleur();

	obj::Obj::Ptr objAffiche;	//l'objet à afficher
	obj::Vertex center;			//le centre du repère d'affichage. Pas encore utilisé

	//fonctions de dessin
	void drawDefault();
	void drawObj();
	void drawCube0(obj::Vertex center);
	void drawCube1(std::vector<obj::Vertex> line);
	void drawFace(const obj::Object::face &fa);
};

#endif