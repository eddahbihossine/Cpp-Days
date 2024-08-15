#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;

}


ScavTrap ::ScavTrap(std:: string name) 
{
	this->_name = name;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{

	if(_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << _name << " can't attack. Not enough hit points or energy points." << std::endl;
		return;
	}
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " for " << _attackDamage << " damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << _name << " can't attack. Not enough hit points or energy points." << std::endl;
	}
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << std::endl;
}