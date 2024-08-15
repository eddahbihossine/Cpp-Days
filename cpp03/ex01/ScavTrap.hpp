#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : public  ClapTrap
{
	public:
		//canonical form
		ScavTrap();
		~ScavTrap();
		ScavTrap(std:: string name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& copy);
		//member functions
		void attack(std::string const & target);
        void guardGate();
};
#endif