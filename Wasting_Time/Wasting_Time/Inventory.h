#pragma once
#include "Items.h"
#include "Weapons.h"
#include "Armor.h"
#include "RedundantHeaderKeepr.h"


class Inventory
{
public:


	Inventory() {}
	~Inventory() {}

	bool inventoryFull();
	template <typename T>
	void addToInventory(T& item);
	template <typename T>
	void removeFromInventory(T& item);


private:
	int max_space = 30;

};


