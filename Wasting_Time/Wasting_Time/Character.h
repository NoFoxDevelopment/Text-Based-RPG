#pragma once

#include <string>
#include "Attributes.h"
#include "Items.h"
#include "Weapons.h"
#include "Armor.h"
#include "Consumables.h"




class Character : public Attributes
{
public:

	enum AdventuringClass
	{
		ARCHER,
		MAGE,
		MONK,
		WARRIOR,
		MAX_CLASSES
	};

	enum EquipmentSlot
	{
		MAINHAND,
		OFFHAND,
		HEAD,
		BODY,
		HANDS,
		LEGS,
		FEET
	};

	Character(std::string name, AdventuringClass advClass, int health, int mana, int str, int vit, int dex, int agi, int intel, int mind) :
		m_name(name)
	{

		switch (advClass)
		{
		case ARCHER:
			Attributes(health, mana, str - 1, vit - 2, dex + 1, agi + 1, intel, mind);
			adventureClass = "Archer";
			break;
		case MAGE:
			Attributes(health - 20, mana + 20, str - 2, vit - 2, dex - 2, agi- 1, intel + 2, mind + 1);
			adventureClass = "Mage";
			break;
		case MONK:
			Attributes(health + 50, mana - 10, str + 1, vit + 1, dex, agi, intel - 2, mind - 1);
			adventureClass = "Monk";
			break;
		case WARRIOR:
			Attributes(health + 100, mana - 50, str + 2, vit + 2, dex - 1, agi - 1, intel - 2, mind - 2);
			adventureClass = "Warrior";
			break;
		}

	}
	~Character()
	{

	}


	std::string getName() { return m_name; }
	std::string getAdCls(){ return adventureClass; }
	

	void setName(std::string name) { m_name = name; }
	void setAdvClass(std::string advclass) { adventureClass = advclass; }
	
	void saveCharacter(std::string path);
	void loadCharacter(std::string path);

	void levelUp(int mEXP);

	void fullInventory();
	int getInventorySize() { return inventory.size(); }
	int getMaxInventorySize() { return max_inventory; }

	void getInventoryItemName();

	void getItemFromDatabase(int itemID);

	void addToInventory(int itemID);

	void removeFromInventory(Items* item);

	void equipItem(Items* item); 
	void unequipItem(Items* item); //check this for memory leaks. Also look for a better way to run both of these functions


	void useItem(Consumables consumable);

private:

	std::string m_name;
	std::string adventureClass;
	int m_exp = 0;
	int m_nextExp;
	int m_level = 1;

	std::vector<Items *> inventory;
	int max_inventory = 30;

	std::vector<Items*> Equipment;
	
	
};
