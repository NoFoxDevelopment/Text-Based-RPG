#include "stdafx.h"
#include "Character.h"
#include <sstream>


void Character::saveCharacter(std::string path)
{
}

void Character::loadCharacter(std::string path)
{
}

void Character::levelUp(int monsterEXP)
{

	m_exp += monsterEXP;

	if (m_exp >= m_nextExp)
	{
		m_level++;

		m_exp -= m_nextExp;

		m_nextExp = ((m_level + 4) * 100) + ((this->getInt() - 5) * 50);

		//stat increases during level up. 
		this->setMaxHealth(this->getMaxHealth() + 50);
		this->setMaxMana(this->getMaxMana() + 20);

		this->setHealth(this->getMaxHealth());
		this->setMana(this->getMaxMana());

		if ((m_level % 2) == 0)
		{
			this->setDex(1);
			this->setAgi(1);
			this->setMnd(1);
			this->setStr(1);
			this->setVit(1);
			this->setInt(1);
		}

	}

	for (int i = 0; i < abilities.size(); i++)
	{
		if (this->m_level >= abilities[i]->getLevelObtained())
		{
			abilities[i]->makeAbilityActive();
		}
	}



}

bool Character::fullInventory()
{
	if (inventory.size() == max_inventory)
		return true;

	return false;
}

void Character::getInventoryItemName()
{
	std::cout << inventory[0]->getItemName() << std::endl;
}


void Character::getItemFromDatabase(int itemID)
{
	int itemFID, str, vit, dex, agi, intel, mnd, wType, wPlacement, aPlacement, hpHeal, mpHeal, stack;
	std::string name;
	std::string descrip;
	bool stackable, isEquipped, poisonHeal;

	std::string stringID;


	std::ifstream infile("Dat Files\\Items\\Items.csv");

	while (!infile.eof())
	{


		std::getline(infile, stringID);

		std::istringstream sstream(stringID);

		std::getline(sstream, stringID, ',');

		itemFID = std::atoi(stringID.c_str());

		if (itemFID == itemID)
		{
			if (itemFID >= 1000 && itemFID <= 1999)
			{
				std::getline(sstream, name, ',');
				std::getline(sstream, descrip, ',');

				std::getline(sstream, stringID, ',');
				isEquipped = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				str = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				vit = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				dex = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				agi = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				intel = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				mnd = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				wType = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				wPlacement = std::atoi(stringID.c_str());

				inventory.push_back(new Weapons(name, descrip, itemFID, static_cast<bool>(isEquipped), str, vit, dex, agi, intel, mnd, static_cast<Weapons::WeaponType>(wType),
					static_cast<Weapons::WeaponPlacement>(wPlacement)));
				break;
			}
			else if (itemFID >= 2000 && itemFID <= 2999)
			{
				std::getline(sstream, name, ',');
				std::getline(sstream, descrip, ',');

				std::getline(sstream, stringID, ',');
				isEquipped = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				str = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				vit = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				dex = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				agi = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				intel = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				mnd = std::atoi(stringID.c_str());

				std::getline(sstream, stringID, ',');
				aPlacement = std::atoi(stringID.c_str());

				inventory.push_back(new Armor(name, descrip, itemFID, static_cast<bool>(isEquipped), str, vit, dex, agi, intel, mnd,
					static_cast<Armor::ArmorPlacement>(aPlacement)));
				break;
			}
			else if (itemFID >= 3000 && itemFID <= 3999)
			{
				//check if item is stackable.


				std::getline(sstream, stringID, ',');
				stackable = std::atoi(stringID.c_str());

				if (static_cast<bool>(stackable))
				{

					for (int i = 0; i < inventory.size(); i++)
					{
						//check to see if the item is already in the inventory. 
						if (itemFID == inventory.at(i)->getItemID())
						{
							//If the item is in the inventory, increment stackable by 1. 
							inventory.at(i)->addToStack();
						}
					}
				}

				//If it is not in the inventory, push_back to inventory. 
				else if (itemFID >= 3000 && itemFID <= 3999)
				{
					std::getline(sstream, name, ',');
					std::getline(sstream, descrip, ',');

					std::getline(sstream, stringID, ',');
					hpHeal = std::atoi(stringID.c_str());

					std::getline(sstream, stringID, ',');
					mpHeal = std::atoi(stringID.c_str());

					std::getline(sstream, stringID, ',');
					poisonHeal = std::atoi(stringID.c_str());

					std::getline(sstream, stringID, ',');
					stack = std::atoi(stringID.c_str());

					inventory.push_back(new Consumables(name, descrip, stackable, itemFID, stack, hpHeal, mpHeal, poisonHeal));
					break;
				}
			}

		}


	}
}

	void Character::addToInventory(int itemID)
	{

		if (fullInventory())
		{
			std::cout << "Your Inventory is full\n";
		}
		else
		{
			getItemFromDatabase(itemID);
		}
	}


	void Character::removeFromInventory(Items* item)
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			if (item->getItemID() == inventory[i]->getItemID())
			{
				inventory.erase(inventory.begin() + i);
				break;
			}
		}
	}

	void Character::equipItem(Items * item) //add in functions to change isEquipped to true
	{


		//equipitem based on wPlacement and aPLacement of items opject. 

		if (item->getItemID() >= 1000 && item->getItemID() <= 1999)
		{
			Weapons* w = dynamic_cast<Weapons*>(item);

			//set armor in a specific place of the equipment vector. 
			switch (w->getItemPlacement())
			{
			case Weapons::WeaponPlacement::MAINHAND:
				Equipment.at(0) = item;
				fillAbilitiesList(w->getWeaponType());
				break;
			case Weapons::WeaponPlacement::OFFHAND:
				Equipment.at(1) = item;
				break;
			}
		}

		if (item->getItemID() >= 2000 && item->getItemID() <= 2999)
		{
			Armor* a = dynamic_cast<Armor*>(item);

			//set armor in a specific place of the equipment vector. 

			switch (a->getItemPlacement())
			{
			case Armor::ArmorPlacement::HEAD:
				Equipment.at(2) = item;
				break;
			case Armor::ArmorPlacement::BODY:
				Equipment.at(3) = item;
				break;
			case Armor::ArmorPlacement::HANDS:
				Equipment.at(4) = item;
				break;
			case Armor::ArmorPlacement::LEGS:
				Equipment.at(5) = item;
				break;
			case Armor::ArmorPlacement::FEET:
				Equipment.at(6) = item;
				break;
			}
		}

	}

	void Character::unequipItem(Items * item) //add in function to change isEquipped to False
	{
		for (int i = 0; i < Equipment.size(); i++)
		{
			if (item->getItemID() == Equipment[i]->getItemID())
			{

				if (i == 0)
				{
					fillAbilitiesList(Weapons::WeaponType::HANDTOHAND);
				}
				Equipment.at(i) = new Items("None", "None", false, 9999, 0);
				
			}
		}
	}

	void Character::initializeEquipment() //this is only run at the beginning of a new game. Basically this is pointless, but I have it here just in case. 
	{
		for (int i = 0; i < 7; i++)
		{
			Equipment.at(i) = new Items("None", "None", false, 9999, 0);
		}
	}

	void Character::useItem(Items* item)
	{
		//use consumable item from the inventory. 
		Consumables* c = dynamic_cast<Consumables*>(item);
		if (c->getHPHeal > 0)
		{
			this->setHealth = this->getHealth + c->getHPHeal();
		}
		else if (c->getMPHeal > 0)
		{
			this->setMana = this->getMana + c->getMPHeal;
		}

		//remove item if it is the last in it's stack, or reduce stack size.
		item->removeFromStack();
	}

	void Character::fillAbilitiesList(Weapons::WeaponType wType)
	{
		//this int is used just to see if the vector 
		
		int id, wSType, levelObtained, damage, MPcost, dtype, AOE, GodAbility, active;
		std::string name;

		std::ifstream infile("Dat Files\\Abilities\\Abilities.csv");

		
		std::string stringID;

		while (!infile.eof)
		{
			std::getline(infile, stringID);

			std::stringstream sstream(stringID);

			std::getline(sstream, stringID, ',');
			id = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			wSType = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			levelObtained = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			damage = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			MPcost = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			dtype = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			AOE = std::atoi(stringID.c_str());
			
			std::getline(sstream, stringID, ',');
			GodAbility = std::atoi(stringID.c_str());

			std::getline(sstream, stringID, ',');
			active = std::atoi(stringID.c_str());
			
			std::getline(sstream, name, ',');

			if (static_cast<Abilities::WeaponSkillType>(wSType) == wType)
			{
				abilities.push_back(new Abilities(id, levelObtained, damage, MPcost, static_cast<Abilities::DamageType>(dtype), static_cast<Abilities::WeaponSkillType>(wSType),
					static_cast<bool>(AOE), static_cast<bool>(GodAbility), static_cast<bool>(active), name));
			}
			
		}
	}