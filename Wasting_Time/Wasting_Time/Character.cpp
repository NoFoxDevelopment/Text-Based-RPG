#include "Character.h"
#include "Character.h"
#include "Character.h"
#include "stdafx.h"
#include "Character.h"



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
