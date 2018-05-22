#pragma once

#include "RedundantHeaderKeepr.h"



class Items
{
public:

	Items() {}

	Items(std::string name, std::string description, bool stackable, int itemID, int stack) :
		m_name(name), m_description(description), m_stackable(stackable), m_itemID(itemID), m_stack(stack)
	{}

	~Items()
	{
	}


	virtual	std::string getItemName() { return m_name; }

	virtual std::string getItemDescription() { return m_description; }

	virtual int getItemID() { return m_itemID; }

	virtual bool getStackable() { return m_stackable; }

	virtual std::string isStackable()
	{
		if (m_stackable)
			return "Yes";

		return "No";
	}

	virtual void addToStack() { m_stack++; }
	virtual void removeFromStack() { m_stack--; }


protected:

	int m_itemID;
	bool m_stackable;
	std::string m_name;
	std::string m_description;
	int m_stack = 1;
};