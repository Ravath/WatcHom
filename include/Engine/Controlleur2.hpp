#ifndef CONTROLLEUR2_HPP
#define CONTROLLEUR2_HPP

#include <memory>
#include "Data\Obj2.hpp"
#include "GL\freeglut.h"

class Controlleur2
{
public:
	~Controlleur2() = default;
	typedef std::shared_ptr<Controlleur2> Ptr;
	//fonction de singleton et d'accès au bidule
	static Ptr get();
	//fonction de rafraichissement utilisée par la fenetre d'affichage
	void drawGL();	//gère les autres fonctions de dessin en fonction du contexte

	//fonctions de chargement
	void loadObj(std::string path);//charge un obj et le sauvegarde ds objAffiche pour l'afficher
	void computeCenter();	//calcule les valeurs du centre selon la taille de l'objet
private:
	Controlleur2();

	obj::Obj2::Ptr objAffiche;	//l'objet à afficher
	obj::Vertex center;			//le centre du repère d'affichage. Pas encore utilisé
	GLuint listObj;

	//fonctions de dessin
	void drawDefault();
	void drawObj();
	void drawCube0(obj::Vertex center);
	void drawCube1(std::vector<obj::Vertex> line);
	void drawFace(const obj::Object::face &fa);
};

#endif