#include "stdafx.h"
#include "Armor.h"

void Armor::loadArmorList(std::string path)
{
	/*std::ifstream inFile(path);
	
	bool isEquipped; 
	int vit;
	int agi;
	int intel; 
	int mnd; 
	int aPlacement;
	std::string name; 


	while (inFile >> isEquipped >> vit >> agi >> intel >> mnd >> aPlacement >> name)
	{
		Armor armor(isEquipped, vit, agi, intel, mnd, static_cast<ArmorPlacement>(aPlacement), name);

		armorList.push_back(armor);
	}*/

}

void Armor::saveArmorList(std::string path)
{
	std::ofstream outFile(path);

	/*for (int i = 0; i < armorList.size(); i++)
	{
		outFile << armorList[i];
	}
*/
}

std::ostream & operator<<(std::ostream & os, Armor armor)
{
	// TODO: insert return statement here

	os << armor.m_isEquipped << ' ' << armor.getVit() << ' ' << armor.getAgi() << ' ' <<
		armor.getInt() << ' ' << armor.getMnd() << ' ' << static_cast<int>(armor.m_aPlacement) <<
		' ' << std::endl;

	return os;
}
