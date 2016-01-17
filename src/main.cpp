#include "Interface\WindowOpenGL.hpp"

#include <Data\PGM3D.hpp>
#include <Data\ComplexeCubique.hpp>
#include <Data\Conversion.hpp>
#include <ctime>

using namespace std;
using namespace sf;
using namespace sfg;
using namespace obj;

void findDoubles(obj::Obj &ob) {
	obj::Vertex v,w;
	cout << to_string(ob.nbrVertices()) << endl;
	for (int i = 1; i <= ob.nbrVertices(); i++) {
		v = ob.getVertex(i);
		for (int j = i+1; j <= ob.nbrVertices(); j++) {
			w = ob.getVertex(j);
			if (v.x == w.x && v.y == w.y && v.z == w.z) std::cout << "doublon" << endl;
		}
	}
}
int main()
{
	PGM3D pgm;
	Obj obj;
	try {
		clock_t begin = clock();/*
		//lecture pgm
		pgm.load("fertility100.pgm");
		cout << "lecture pgm en " << double(clock() - begin) / CLOCKS_PER_SEC << endl;
		//conversion pgm vers complexe
		begin = clock();
		shared_ptr<ComplexeCubique> cc = Conversion::PGM3D2ComplexeCubique(pgm);
		cout << "conversion pgm>C en " << double(clock() - begin) / CLOCKS_PER_SEC << endl;*/
		//lecture obj
		begin = clock();
		obj.load("fertility100_11_V.obj");
		cout << "lecture obj en " << double(clock() - begin) / CLOCKS_PER_SEC << endl;
		//conversion complexe vers obj
		begin = clock();
		findDoubles(obj);
		cout << "conversion C>Obj en " << double(clock() - begin) / CLOCKS_PER_SEC << endl;
		//conversion pgm vers obj
		begin = clock();

		cout << "conversion pgm>obj en " << double(clock() - begin) / CLOCKS_PER_SEC << endl;
	}
	catch (FileError f) {
		cout << f.what();
	}
	char x;
	cin >> x;
/*
	WindowOpenGL app_window;
	app_window.run();
	*/
	return 0;
}