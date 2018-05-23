#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <iostream>





class Abilities
{
public:

	enum DamageType
	{
		BLUNT,
		PIERCING,
		SLASHING,
		MAX_DMG_TYPES
	};

	Abilities(int levelObtained, int damage, int MPcost, DamageType dtype, bool AOE, bool GodAbility, bool Active, std::string Abilityname):
		m_levelObtained(levelObtained), m_damage(damage), m_MPcost(MPcost), m_dtype(dtype), m_AOE(AOE), m_GodAbility(GodAbility), m_active(Active), m_AbilityName(Abilityname)
	{}

	~Abilities()
	{}


	std::string getAbilityName()	{ return m_AbilityName; }
	DamageType getDamageType()		{ return m_dtype; }
	int getMPcost()					{ return m_MPcost; }
	int getLevelObtained()			{ return m_levelObtained; }
	int getDamage()					{ return m_damage; }
	bool getAOE()					{ return m_AOE; }
	bool GodAbility()				{ return m_GodAbility; }

	void makeAbilityActive()		{ this->m_active = true; }

private:

	int m_levelObtained;
	int m_damage;
	int m_MPcost;
	DamageType m_dtype;
	bool m_AOE;
	bool m_GodAbility;
	bool m_active;
	std::string m_AbilityName;


};

