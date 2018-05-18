#pragma once
#include "Items.h"
#include "Attributes.h"
#include "RedundantHeaderKeepr.h"

class Weapons : public Items, public Attributes
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

	Weapons(std::string name, std::string description, int itemID, bool isEquipped, int str, int vit, int dex, int agi, int intel, int mnd, WeaponType wType, WeaponPlacement wPlacement) :
		Items(name, description, false, itemID), m_isEquipped(isEquipped), Attributes(0, 0, str, vit, dex, agi, intel, mnd), m_wType(wType), m_wPlacement(wPlacement)
	{}

	~Weapons()
	{}

	void loadWeaponList(std::string path);
	void saveWeaponList(std::string path);

	friend std::ostream& operator<<(std::ostream& os, Weapons weapon);

	std::string getItemName() { return m_name; }

private:

	bool m_isEquipped;
	WeaponType m_wType;
	WeaponPlacement m_wPlacement;


};




