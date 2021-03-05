#include "SuperHero.h"
#include "Hero.h"
using namespace std;
namespace sict {
	
	SuperHero::SuperHero(const char* m_name, int m_health, int m_strength, int attackbonus, int defendbonus) : Hero(m_name, m_health, m_strength) {
		m_defendbonus = defendbonus;
		m_attackbonus = attackbonus;
	}
	int SuperHero::defend() const {
		if (m_defendbonus == 0) {
			return 0;
		}
		else {
			return m_defendbonus > 0 ? m_defendbonus : 0;
		}
	}
	SuperHero::SuperHero()
	{
		m_defendbonus = 0;
		m_attackbonus = 0;
	}
	int SuperHero::attackStrength() const {
		if (m_attackbonus == 0) {
			return 0;
		}
		else {
			return Hero::attackStrength() + m_attackbonus > 0 ? Hero::attackStrength() + m_attackbonus : 0;
		}
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		cout << "Super Fight! " << first << " vs " << second << " : ";
		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;
		int rounds = 0;
		while (A.isAlive() && B.isAlive() && rounds < max_rounds) {
			rounds++;
			A.operator -=(B.attackStrength() - A.defend());
			B.operator -=(A.attackStrength() - B.defend());
		}
		bool draw;

		if (A.isAlive() && B.isAlive()) {
			draw = true;
		}
		else {
			draw = false;
		}
		if (draw) {
			winner = &first;
		}
		else if (A.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}
		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}

}