#include "Engine\Controlleur2.hpp"
#include <iostream>

using namespace std;
using namespace obj;
Controlleur2::Controlleur2() {
	glEnable(GL_DEPTH_TEST);
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
}
Controlleur2::Ptr Controlleur2::get() {
	static  Controlleur2::Ptr inst = Controlleur2::Ptr(new Controlleur2);
	return inst;
}
void Controlleur2::drawGL() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(center.x, center.y, center.z);

	//affichage spécifique
	if (objAffiche == nullptr) {
		drawDefault();
	}
	else {
		glColor3b(10, 100, 10);
		drawObj();
	}
}
void Controlleur2::drawDefault() {
	glBegin(GL_QUADS);
	glVertex3f(0.f, 1.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(1.f, 0.f, 0.f);
	glVertex3f(1.f, 1.f, 0.f);
	glEnd();
}

void Controlleur2::drawObj() {
	if (listObj == 0) {
		Object obj;
		listObj = glGenLists(1);
		glNewList(listObj, GL_COMPILE);
		for (int i = 0; i < objAffiche->nbrObjects(); i++) {
			obj = objAffiche->getObject(i);
			for (Object::face f : obj.getFaces()) {
				drawFace(f);
			}
		}
		glEndList();
		computeCenter();
	}
	glPushMatrix();
	glCallList(listObj);
	glPopMatrix();
}
void Controlleur2::drawCube0(obj::Vertex center) {

}
void Controlleur2::drawCube1(std::vector<obj::Vertex> line) {

}
void Controlleur2::drawFace(const Object::face &fa) {
	Vertex v;
	glBegin(GL_POLYGON);
	for (int i : fa) {
		v = objAffiche->getVertex(i);
		glVertex3f(v.x, v.y, v.z);
	}
	glEnd();
}
//charge un obj et le sauvegarde ds objAffiche pour l'afficher
void Controlleur2::loadObj(std::string path) {
	try {
		objAffiche = Obj2::Ptr(new Obj2());
		objAffiche->load(path);
	}
	catch (FileError fe) {
		std::cout << fe.what();
	}
	catch (exception e) {
		std::cout << e.what();
	}
}
void Controlleur2::computeCenter() {
	center.x = -50.f;
	center.y = -50.f;
	center.z = -50.f;
}