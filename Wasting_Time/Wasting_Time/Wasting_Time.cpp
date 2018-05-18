// Wasting_Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Maps.h"
#include "Text.h"
#include "Character.h"
#include "Magic.h"



int main()
{
	Character character("Travis", Character::AdventuringClass::WARRIOR, 100, 50, 5,5,5,5,5,5);

	while (true)
	{

		
		character.addToInventory(1000);

		std::cout << character.getInventorySize() << std::endl;

		character.getInventoryItemName();
		
	}

	

    return 0;
}

