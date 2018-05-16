#include "stdafx.h"
#include "Abilities.h"


void Abilities::loadAbilities(std::string path)
{

	std::ifstream infile(path);

	int levelObtained;
	int damage;
	int MPcost;
	int range;
	int damageType;
	bool AOE;
	bool GodAbility;
	bool ActiveAbility;
	std::string abilityName;

	while (infile >> levelObtained >> damage >> MPcost >> range >> damageType >> AOE >> GodAbility >> ActiveAbility >> abilityName)
	{
		Abilities ability(levelObtained, damage, MPcost, range, static_cast<DamageType>(damageType), AOE, GodAbility, ActiveAbility, abilityName);

		abilitieslist.push_back(ability);
	}

}

void Abilities::saveAbilities(std::string path)
{
	std::ofstream outFile(path);



	for (int i = 0; i < abilitieslist.size(); i++)
	{
		

		outFile << abilitieslist[i];

	}

}

std::ostream & operator<<(std::ostream & os, Abilities ability)
{
	// TODO: insert return statement here

	os << ability.m_levelObtained << ' ' << ability.m_damage << ' ' << ability.m_MPcost << ' ' << ability.m_range << ' ' << static_cast<int>(ability.m_dtype) << ' '
	<< ability.m_AOE << ' ' << ability.m_GodAbility << ' ' << ability.m_AbilityActive << ' ' << ability.m_AbilityName << std::endl;
}
