#pragma once
#include "Items.h"
#include "Attributes.h"
#include "RedundantHeaderKeepr.h"

class Armor : public Items, public Attributes
{
public:

	enum ArmorPlacement
	{
		HEAD,
		BODY,
		HANDS,
		LEGS,
		FEET,
		MAX_PLACEMENT
	};

	Armor() {}

	Armor(std::string name, std::string description, int itemID, bool isEquipped, int str, int vit, int dex, int agi, int intel, int mnd, ArmorPlacement aPlacement) :
		Items(name, description, false, itemID),m_isEquipped(isEquipped), Attributes(0, 0, str, vit, dex, agi, intel, mnd), m_aPlacement(aPlacement)
	{

	}
	
	~Armor()
	{}

	void loadArmorList(std::string path);
	void saveArmorList(std::string path);

	friend std::ostream& operator<<(std::ostream& os, Armor armor);

private:

	bool m_isEquipped; 
	ArmorPlacement m_aPlacement;
};

