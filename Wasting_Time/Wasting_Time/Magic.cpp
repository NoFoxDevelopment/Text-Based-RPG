#include "stdafx.h"
#include "Magic.h"

//std::vector<Magic> spellList;



void Magic::loadSpells(std::string path)
{
	std::ifstream infile;

	infile.open(path);

	int levelObtained;
	int damage;
	int MPcost;
	int element;
	int range;
	bool AOE;
	bool GodMagic;
	bool spellActive;
	std::string spellname;

	if (!infile)
		std::cout << "File failed to load\n";
	else
	{
		while (infile >> levelObtained >> damage >> MPcost >> element >> range >> AOE >> GodMagic >> spellActive >> spellname)
		{
			

			Magic spell(levelObtained, damage, MPcost, static_cast<Element>(element), range, AOE, GodMagic, spellActive, spellname);

			spellList.push_back(spell);

		
		}
	}
}

void Magic::SaveSpellState(std::string path)
{
	std::ofstream outFile(path);

	

	for (int i = 0; i < spellList.size(); i++)
	{


		outFile << spellList[i];

	}

}

std::ostream & operator<<(std::ostream& os, Magic magic)
{
	os << magic.m_levelObtained << ' ' << magic.m_damage << ' ' <<
		magic.m_MPcost << ' ' << static_cast<int>(magic.m_element) << ' ' << magic.m_range << ' ' <<
		magic.m_AOE << ' ' << magic.m_GodMagic << ' ' << magic.m_spellname << std::endl;

	return os;
}
