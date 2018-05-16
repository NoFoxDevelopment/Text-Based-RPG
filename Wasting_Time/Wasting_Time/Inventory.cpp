#include "stdafx.h"
#include "Inventory.h"

bool Inventory::inventoryFull()
{
	if (inventory.size() == max_space)
	{
		return true;
	}

	return false;
}

template<typename T>
inline void Inventory::addToInventory(T& item)
{

	inventory.push_back(item);
}

template<typename T>
inline void Inventory::removeFromInventory(T & item)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (item == inventory.at(i))
		{
			std::swap(inventory.at(i), inventory.at(inventory.end());
		}
	}
	inventory.pop_back();
}