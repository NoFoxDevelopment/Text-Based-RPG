#pragma once

#include <string>
#include "Attributes.h"
#include "Items.h"
#include "Weapons.h"
#include "Armor.h"
#include "Consumables.h"
#include "Abilities.h"



class Character : public Attributes
{
public:


	Character(std::string name, int health, int mana, int str, int vit, int dex, int agi, int intel, int mind) :
		m_name(name), Attributes(health, mana, str, vit, dex, agi, intel, mind)
	{

	}
	~Character()
	{

	}


	std::string getName() { return m_name; }
	std::string getAdCls() { return adventureClass; }


	void setName(std::string name) { m_name = name; }
	void setAdvClass(std::string advclass) { adventureClass = advclass; }

	void saveCharacter(std::string path);
	void loadCharacter(std::string path);

	void levelUp(int mEXP);

	bool fullInventory();
	int getInventorySize() { return inventory.size(); }
	int getMaxInventorySize() { return max_inventory; }

	void getInventoryItemName();

	void getItemFromDatabase(int itemID);

	void addToInventory(int itemID);

	void removeFromInventory(Items* item);

	void equipItem(Items* item);
	void unequipItem(Items* item); //check this for memory leaks. Also look for a better way to run both of these functions
	void initializeEquipment();


	void useItem(Items* item);


	void fillAbilitiesList(Weapons::WeaponType wType);

private:

	std::string m_name;
	std::string adventureClass;
	int m_exp = 0;
	int m_nextExp;
	int m_level = 1;

	std::vector<Items *> inventory;
	int max_inventory = 30;

	std::vector<Items*> Equipment;

	std::vector<Abilities*> abilities;

};
