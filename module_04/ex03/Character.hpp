#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    AMateria    *inventory[4];
    std::string name;
    Character   *matryoshka;
    int         is_matryoshka;

public:
    Character();
    Character(std::string nName);
    Character(const Character& ref);
    ~Character();

    Character&	operator=(const Character& ref);

    std::string const & getName() const;
	virtual void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
