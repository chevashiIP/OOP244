#ifndef HERO_H
#define HERO_H

#include <iostream>
using namespace std;
const int max_rounds = 100;
namespace sict {
	class Hero {
		char m_name[41];
		int m_health;
		int m_attack;
	public:
		Hero();
		Hero(const char name[], int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend ostream& operator << (ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif