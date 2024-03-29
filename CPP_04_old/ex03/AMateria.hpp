#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
	unsigned int _xp;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& copy);
	virtual ~AMateria() {}
	std::string const & getType() const;	//Returns the materia type
	unsigned int getXP() const;				//Returns the Materia's XP
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter&);
};

#endif
