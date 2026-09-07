#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
  private:
	std::string Name;
	int HP;
	int EP;
	int AD;

  public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	bool areYouAlive();
	void showStatus();

	std::string getName() const;
	int getHP() const;
	int getEP() const;
	int getAD() const;

	void setAD(int val);
};

#endif
