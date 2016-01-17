#include "Engine\Controlleur.hpp"
#include "GL\freeglut.h"
#include <iostream>

using namespace std;
using namespace obj;

Controlleur::Controlleur()
{
}

Controlleur::~Controlleur()
{
}
Controlleur::Ptr Controlleur::get() {
	static  Controlleur::Ptr inst = Controlleur::Ptr(new Controlleur);
	return inst;
}
void Controlleur::drawGL() {
	//paramétrages

	//glViewport(0, 0, static_cast<int>(window.getSize().x), static_cast<int>(window.getSize().y));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	static const auto pi = 3.1415926535897932384626433832795f;
	static const auto fov = 90.f;
	static const auto near_distance = .1f;
	static const auto far_distance = 100.f;
	static const auto aspect = 800.f / 600.f;

	auto frustum_height = std::tan(fov / 360 * pi) * near_distance;
	auto frustum_width = frustum_height * aspect;

	glFrustum(-frustum_width, frustum_width, -frustum_height, frustum_height, near_distance, far_distance);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-.50f, -.50f, -50.f);

	//affichage spécifique
	if (objAffiche == nullptr) {
		drawDefault();
	}
	else {
		drawObj();
	}
}
void Controlleur::drawDefault() {
	glBegin(GL_QUADS);
	glVertex3f(0.f, 1.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(1.f, 0.f, 0.f);
	glVertex3f(1.f, 1.f, 0.f);
	glEnd();
}
void Controlleur::drawObj() {
	Object obj;
	for (int i = 0; i < objAffiche->nbrObjects(); i++) {
		obj = objAffiche->getObject(i);
		for (Object::face f : obj.getFaces()) {
			drawFace(f);
		}
	}
}
void Controlleur::drawCube0(obj::Vertex center) {

}
void Controlleur::drawCube1(std::vector<obj::Vertex> line) {

}
void Controlleur::drawFace(const Object::face &fa) {
	Vertex v;
	glBegin(GL_POLYGON);
	for (int i : fa) {
		v = objAffiche->getVertex(i);
		glVertex3f(v.x, v.y, v.z);
	}
	glEnd();
}
//charge un obj et le sauvegarde ds objAffiche pour l'afficher
void Controlleur::loadObj(std::string path) {
	try {
		objAffiche = Obj::Ptr(new Obj());
		objAffiche->load(path);
	}
	catch (FileError fe) {
		std::cout << fe.what();
	}
	catch (exception e) {
		std::cout << e.what();
	}
}