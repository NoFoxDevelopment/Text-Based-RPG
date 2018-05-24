#include "stdafx.h"
#include "Weapons.h"

void Weapons::loadWeaponList(std::string path)
{
	/*std::ifstream inFile(path);

	bool isEquipped;
	int str;
	int dex;
	int wtype;
	int wPlacement;
	std::string name;

	while (inFile >> isEquipped >> str >> dex >> wtype >> wPlacement >> name)
	{
		Weapons weapon(isEquipped, str, dex, static_cast<WeaponType>(wtype), static_cast<WeaponPlacement>(wPlacement), name);

		weaponList.push_back(weapon);
	}*/

}

void Weapons::saveWeaponList(std::string path)
{
	/*std::ofstream outFile(path);

	for (int i = 0; i < weaponList.size(); i++)
	{
		outFile << weaponList[i];
	}*/
}

std::ostream & operator<<(std::ostream & os, Weapons weapon)
{
	// TODO: insert return statement here
	os << weapon.m_isEquipped << ' ' << weapon.getStr() << ' ' << weapon.getDex() << ' ' << weapon.m_wType << ' ' 
		<< weapon.m_wPlacement << ' ' << std::endl;

	return os;
}
