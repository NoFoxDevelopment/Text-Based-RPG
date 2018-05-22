#pragma once

#include "Items.h"
#include "RedundantHeaderKeepr.h"



class Consumables : public Items
{
public:

	Consumables(std::string name, std::string descript, bool stackable, int itemID, int stack, int hpHeal, int mpHeal, bool healPoison) :
		Items(name, descript, stackable, itemID, stack), m_hpHeal(hpHeal), m_mpHeal(mpHeal), m_healPoison(healPoison)
	{}

	~Consumables()
	{}


	std::string getItemName() { return m_name; }
	std::string getItemDescription() { return m_description; }

	int getItemID() { return m_itemID; }
	bool getStackable() { return m_stackable; }

	int getHPHeal() { return m_hpHeal; }
	int getMPHeal() { return m_mpHeal; }

	bool getPoisonHeal() { return m_healPoison; }

	void addToStack() { m_stack++; }
	void removeFromStack() { m_stack--; }


private:
	int m_hpHeal;
	int m_mpHeal;
	bool m_healPoison;


};