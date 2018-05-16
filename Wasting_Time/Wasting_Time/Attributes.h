#pragma once


class Attributes
{

public:

	Attributes(int health, int mana, int str, int vit, int dex, int agi, int intel, int mind):
		m_health(health), m_mana(mana), m_str(str), m_vit(vit), m_dex(dex), m_agi(agi), m_intel(intel), m_mind(mind)
	{}

	Attributes()
	{

	}

	int			getHealth() { return m_health; }
	int			getMana()	{ return m_mana; }

	int			getMaxHealth()	{ return m_maxHealth; }
	int			getMaxMana()	{ return m_maxMana; }

	int			getStr() { return m_str; }
	int			getVit() { return m_vit; }
	int			getDex() { return m_dex; }
	int			getAgi() { return m_agi; }
	int			getInt() { return m_intel; }
	int			getMnd() { return m_mind; }


	void		setHealth(int health)	{ m_health += health; }
	void		setMana(int mana)		{ m_mana += mana; }

	void		setMaxHealth(int health)	{ m_maxHealth += health; }
	void		setMaxMana(int mana)		{ m_maxMana += mana; }

	void		setStr(int str) { m_str += str; }
	void		setVit(int vit) { m_vit += vit; }
	void		setDex(int dex) { m_dex += dex; }
	void		setAgi(int agi) { m_agi += agi; }
	void		setInt(int inl) { m_intel += inl; }
	void		setMnd(int mnd) { m_mind += mnd; }

private: 

	int m_maxHealth;
	int m_health;
	int m_maxMana;
	int m_mana;
	int m_str;
	int m_vit;
	int m_dex;
	int m_agi;
	int m_intel;
	int m_mind;

};