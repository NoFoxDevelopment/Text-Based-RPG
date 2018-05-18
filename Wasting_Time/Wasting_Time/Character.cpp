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
		this->setMaxHealth(50);
		this->setMaxMana(20);

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

	

}

void Character::getInventoryItemName()
{
	std::cout << inventory[0]->getItemName() << std::endl;
}

void Character::getItemFromDatabase(int itemID)
{
	int itemFID , str, vit, dex, agi, intel, mnd, wType, wPlacement, aPlacement;
	std::string name;
	std::string descrip;
	bool stackable;
	bool isEquipped;

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
		}
		else
		{
			//infile.ignore(1000, '\n');
		}
	}

	
}

void Character::addToInventory(int itemID)
{

	getItemFromDatabase(itemID);

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