#include <string>
#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"


int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	} {
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	 } {
		Weapon club = Weapon("crude spiked club");
		HumanA *jim = new HumanA("pointer jim", club);
		(*jim).attack();
		club.setType("some other type of club");
		(*jim).attack();
		delete jim;
	} {
		Weapon club = Weapon("crude spiked club");
		HumanB *jim = new HumanA("Jim casted pointer", club);
		(*jim).attack();
		club.setType("some other type of club");
		(*jim).attack();
		delete jim;
	 }
}

