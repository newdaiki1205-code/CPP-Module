#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "./ClapTrap.hpp"
# include "./FragTrap.hpp"
# include "./ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string name;

  public:
	DiamondTrap(std::string givenName);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void whoAmI();
	using ScavTrap::attack;
};

#endif
