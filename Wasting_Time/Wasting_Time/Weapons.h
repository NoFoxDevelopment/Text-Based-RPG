#pragma once
#include "Attributes.h"
#include <fstream>
#include <string>
#include <vector>


class Weapons : public Attributes
{
public:

	enum WeaponType
	{
		SOWRD,
		SHIELD,
		AXE,
		CLUB,
		STAFF,
		BOW,
		MAX_WEAPON_TYPES
	};

	enum WeaponPlacement
	{
		MAINHAND,
		OFFHAND
	};

	Weapons() {}

	Weapons(bool isEquipped, int str, int dex, WeaponType wType, WeaponPlacement wPlacement, std::string name) :
		m_isEquipped(isEquipped), Attributes(0, 0, str, 0, dex, 0, 0, 0), m_wType(wType), m_wPlacement(wPlacement), 
		m_name(name)
	{}

	~Weapons()
	{}

	void loadWeaponList(std::string path);
	void saveWeaponList(std::string path);

	friend std::ostream& operator<<(std::ostream& os, Weapons weapon);

private:

	bool m_isEquipped;
	std::string m_name;
	WeaponType m_wType;
	WeaponPlacement m_wPlacement;


};

extern std::vector<Weapons> weaponList;


