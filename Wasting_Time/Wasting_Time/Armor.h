#pragma once
#include "Attributes.h"
#include <string>
#include <fstream>
#include <vector>

class Armor : public Attributes
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

	Armor(bool isEquipped, int vit, int agi, int intel, int mnd, ArmorPlacement aPlacement, std::string name) :
		m_isEquipped(isEquipped), Attributes(0, 0, 0, vit, 0, agi, intel, mnd), m_aPlacement(aPlacement), m_name(name)
	{

	}
	
	~Armor()
	{}

	void loadArmorList(std::string path);
	void saveArmorList(std::string path);

	friend std::ostream& operator<<(std::ostream& os, Armor armor);

private:

	bool m_isEquipped; 
	std::string m_name;
	ArmorPlacement m_aPlacement;
};

extern std::vector<Armor> armorList;