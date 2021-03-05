#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"
namespace sict {
	class SuperHero : public Hero {
		int m_attackbonus;
		int m_defendbonus;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int attackbonus, int defendbonus);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero & operator*(const SuperHero &, const SuperHero &);
}
#endif