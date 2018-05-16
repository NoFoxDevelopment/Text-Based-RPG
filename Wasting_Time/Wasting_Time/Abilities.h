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

	Abilities(int levelObtained, int damage, int MPcost, int range, DamageType dtype, bool AOE, bool GodAbility, bool AbilityActive, std::string Abilityname):
		m_levelObtained(levelObtained), m_damage(damage), m_MPcost(MPcost), m_range(range), m_dtype(dtype), m_AOE(AOE), m_GodAbility(GodAbility), 
		m_AbilityActive(AbilityActive), m_AbilityName(Abilityname)
	{}

	~Abilities()
	{}

	static void loadAbilities(std::string path);
	static void saveAbilities(std::string path);

	friend std::ostream& operator<<(std::ostream& os, Abilities ability);

	void setAbilityActive()
	{
		this->m_AbilityActive = true;
	}

private:

	int m_levelObtained;
	int m_damage;
	int m_MPcost;
	int m_range;
	DamageType m_dtype;
	bool m_AOE;
	bool m_GodAbility;
	bool m_AbilityActive;
	std::string m_AbilityName;


};

extern std::vector<Abilities> abilitieslist;