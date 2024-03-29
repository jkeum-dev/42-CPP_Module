#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(Brain const &copy);
	Brain& operator=(Brain const &copy);
	~Brain();
	std::string const & getIdea(int index) const;
};

#endif
