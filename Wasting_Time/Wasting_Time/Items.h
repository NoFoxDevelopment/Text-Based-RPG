#pragma once

#include "RedundantHeaderKeepr.h"



class Items
{
public:

	Items() {}

	Items(std::string name, std::string description, bool stackable, int itemID):
		m_name(name), m_description(description), m_stackable(stackable), m_itemID(itemID)
	{}

	~Items()
	{
	}


	virtual	std::string getItemName() { return m_name; }

	std::string getItemDescription() { return m_description; }

	int getItemID() { return m_itemID; }


	std::string isStackable()
	{
		if (m_stackable)
			return "Yes";

		return "No";
	}


	void loadItems(std::string path);
	

protected:

	int m_itemID;
	bool m_stackable;
	std::string m_name;
	std::string m_description;

};