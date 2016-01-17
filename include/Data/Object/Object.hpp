#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>
namespace obj{
class Object
{
public:
	typedef std::vector<int> face;
	Object() = default;
	Object(std::string name);
	~Object() = default;
	int addFace(face f);	//retourne le numéro de la face
	face& getFace(int n);
	void setName(std::string name);
	std::string& getName();
	std::vector<face>& getFaces();
private:
	std::string nom;
	std::vector<face> faces;
};
}

#endif