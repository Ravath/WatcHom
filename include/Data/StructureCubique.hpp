#pragma once
#ifndef STRUCTURE_CUBIQUE_HPP
#define STRUCTURE_CUBIQUE_HPP

#include <exception>
#include <string>

struct coord {
	int x, y, z;
} ;

/** Template de gestion de structures en 3 dimensions */
template<typename D>
class StructureCubique
{
public:
	enum Axe { x = 0, y = 1, z = 2 };
	StructureCubique();
	StructureCubique(StructureCubique &copy);
	StructureCubique(int xSize, int ySize, int zSize);
	virtual ~StructureCubique();

	//fonctions d'acc�s donn�es
	//charge au d�veloppeur de g�rer la port�e d'acc�s (utiliser without)
	virtual bool isEmpty(int x, int y, int z) const;
	virtual bool isOccupied(int x, int y, int z) const;
	virtual void set(int x, int y, int z, D val);
	virtual D get(int x, int y, int z) const;
	//�quivalents avec position en consid�rant en parcours selon x puis y puis z
	//x = (pos			)% tx;
	//y = (pos / tx		)% ty;
	//z = (pos / (tx*ty))% tz
	virtual bool isEmpty(int pos) const;
	virtual bool isOccupied(int pos) const;
	virtual void set(int pos, D val);
	virtual D get(int pos) const;
	//check position
	virtual bool without(int x, int y, int z) const;//fonction maudite?????????????
	virtual bool without(int pos) const;
	//getters metaData
	virtual int getSize(Axe axe) const;
	virtual int nbrCubes() const;

	//fonctions d'initialisation
	/*Assigne la m�me valeur � toutes les donn�es*/
	virtual void initVal(D val);
	/**initialise le tableau de donn�es
	  *en param�tres : tableau {x,y,z} */
	virtual void setDataSize(int p_size[3]);
	/* recopie les valeurs. limit� par la taille du plus petit */
	virtual void copy(StructureCubique &cp);

	//conversion de position vers coordo et r�ciproque
	virtual int coord2pos(int x, int y, int z)const;
	virtual coord pos2coord(int pos)const;
private:

protected:
	int size[3];	//dimensions du PGM3D selon les 3 axes
	int squareSize;	// taille_x * taille_y
	char ***data;	//donn�es dans les trois dimensions
					//tableau de z vers x. lorsque boucle, favoriser les x mouvants
	
}; 

#include "../../src/Data/StructureCubique.tpp"

/*
 *Classe d'exception pour les pb de m�moire
 *
 */
class DataError : public std::exception
{
public:
	DataError(std::string const& phrase = "Data Error") throw() :m_phrase(phrase) {}

	virtual const char* what() const throw()
	{
		return m_phrase.c_str();
	}

	virtual ~DataError() throw()
	{}

private:
	std::string m_phrase;            //Description de l'erreur
};

#endif
