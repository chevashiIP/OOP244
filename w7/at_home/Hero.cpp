#include <cstring>
#include <iostream>
#include "Hero.h"
using namespace std;
namespace sict {
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_health = 0;
		m_attack = 0;
	}
	Hero::Hero(const char name[], int health, int attack)
	{
		strcpy(m_name, name);
		m_health = health;
		m_attack = attack;
	}
	void Hero::operator-=(int attack)
	{
		if (attack > 0) {
			m_health -= attack;
		}
	}
	bool Hero::isAlive() const
	{
		return m_health > 0;
	}
	int Hero::attackStrength() const
	{
		if (m_attack == 0) {
			return 0;
		}
		else {
			return m_attack;
		}
	}
	ostream & operator<<(ostream & os, const Hero & hero)
	{
		if (hero.m_name == '\0') {
			os << "No Hero";
		}
		else {
			os << hero.m_name;
		}
		return os;
	}
	const Hero & operator*(const Hero & first, const Hero & second)
	{
		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		Hero f = first;
		Hero s = second;
		const Hero *winner = nullptr;
		int rounds = 0;
		while(f.isAlive() && s.isAlive() && rounds < max_rounds){
			rounds++;
			f -= s.attackStrength();
			s -= f.attackStrength();
		}
		bool draw;
		if (f.isAlive() && s.isAlive()) {
			draw = true;
		}
		else {
			draw = false;
		}
		if (draw) {
			winner = &first;
		}
		else if (f.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}
		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}
}