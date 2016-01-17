#include "Object.hpp"

namespace obj {

Object::Object(std::string name) {
	nom = name;
}
int Object::addFace(Object::face f) {
	faces.push_back(f);
	return faces.size() - 1;//car forcement le dernier //index
}
Object::face& Object::getFace(int n) {
	return faces[n];
}
void Object::setName(std::string name) {
	nom = name;
}
std::string& Object::getName() {
	return nom;
}
std::vector<Object::face>& Object::getFaces() {
	return faces;
}
}