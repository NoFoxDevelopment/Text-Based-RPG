#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

class Magic
{

public:

	
	enum Element
	{
		FIRE,
		WATER,
		WIND,
		EARTH,
		LIGHT,
		DARK,
		VOID,
		MAX_ELEMENTS
	};


	Magic()
	{}

	Magic(int levelObtained, int damage, int MPcost, Element element, int range, bool AOE, bool GodMagic, bool spellActive, std::string spellname) :
		m_levelObtained(levelObtained), m_damage(damage), m_MPcost(MPcost), m_element(element), m_range(range), m_AOE(AOE), m_GodMagic(GodMagic), 
		m_spellActive(spellActive), m_spellname(spellname)
	{}

	~Magic()
	{}

	static void loadSpells(std::string path);
	static void SaveSpellState(std::string path);

	friend std::ostream& operator<<(std::ostream& os, Magic magic);

	void setSpellActive()
	{
		this->m_spellActive = true;
	}

private:

	int m_levelObtained;
	int m_damage;
	int m_MPcost;
	Element m_element;
	int m_range;
	bool m_AOE = false;
	bool m_GodMagic = false;
	bool m_spellActive = false;
	std::string m_spellname;

};

extern std::vector<Magic> spellList;