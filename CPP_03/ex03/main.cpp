#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap jkeum("jkeum");
	DiamondTrap hyunlee("hyunlee");
	DiamondTrap me;

	me = jkeum;
	me.attack(hyunlee.getName());
	hyunlee.takeDamage(me.getAttackDamage());
	hyunlee.beRepaired(10);
	me.guardGate();
	me.highFivesGuys();
	me.whoAmI();
	hyunlee.whoAmI();
	return (0);
}
