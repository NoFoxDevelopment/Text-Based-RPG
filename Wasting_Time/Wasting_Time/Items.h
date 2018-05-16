#pragma once

#include "RedundantHeaderKeepr.h"



class Items
{
public:

	Items() {}

	Items(int stack, int restoreHP, int restoreMP, std::string name, std::string description):
		max_stack(stack), m_restoreHP(restoreHP), m_restoreMP(restoreMP), m_name(name), m_description(description)
	{}

	~Items()
	{
	}


	std::string getItemName() { return m_name; }

	std::string getItemDescription() { return m_description; }

	int getRestoreHP() { return m_restoreHP; }
	int getRestoreMP() { return m_restoreMP; }

	void loadItems(std::string path);
	

private:

	int max_stack;

	int m_restoreHP;
	int m_restoreMP;
	std::string m_name;
	std::string m_description;

};