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
		SHIELD
	};

	enum WeaponPlacement
	{
		EMPTY,
		MAINHAND,
		OFFHAND
	};

	Weapons() {}

	Weapons(std::string name, std::string description, int itemID, bool isEquipped, int str, int vit, int dex, int agi, int intel, int mnd, WeaponType wType, WeaponPlacement wPlacement) :
		Items(name, description, false, itemID, 1), m_isEquipped(isEquipped), Attributes(0, 0, str, vit, dex, agi, intel, mnd), m_wType(wType), m_wPlacement(wPlacement)
	{}

	~Weapons()
	{}

	std::string getItemName() { return m_name; }

	std::string getItemDescription() { return m_description; }

	int getItemID() { return m_itemID; }

	WeaponPlacement getItemPlacement() { return m_wPlacement; }

	int			getStr() { return m_str; }
	int			getVit() { return m_vit; }
	int			getDex() { return m_dex; }
	int			getAgi() { return m_agi; }
	int			getInt() { return m_intel; }
	int			getMnd() { return m_mind; }

private:

	bool m_isEquipped;
	WeaponType m_wType;
	WeaponPlacement m_wPlacement;


};