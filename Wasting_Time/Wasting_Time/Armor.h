#pragma once
#include "Items.h"
#include "Attributes.h"
#include "RedundantHeaderKeepr.h"

class Armor : public Items, public Attributes
{
public:

	enum ArmorPlacement
	{
		EMPTY,
		HEAD,
		BODY,
		HANDS,
		LEGS,
		FEET,
		MAX_PLACEMENT
	};

	Armor() {}

	Armor(std::string name, std::string description, int itemID, bool isEquipped, int str, int vit, int dex, int agi, int intel, int mnd, ArmorPlacement aPlacement) :
		Items(name, description, false, itemID, 1),m_isEquipped(isEquipped), Attributes(0, 0, str, vit, dex, agi, intel, mnd), m_aPlacement(aPlacement)
	{

	}
	
	~Armor()
	{}

	std::string getItemName() { return m_name; }
	std::string getItemDescription() { return m_description; }

	int getItemID() { return m_itemID; }

	ArmorPlacement getItemPlacement() { return m_aPlacement; }

	int			getStr() { return m_str; }
	int			getVit() { return m_vit; }
	int			getDex() { return m_dex; }
	int			getAgi() { return m_agi; }
	int			getInt() { return m_intel; }
	int			getMnd() { return m_mind; }

private:

	bool m_isEquipped; 
	ArmorPlacement m_aPlacement;
};

