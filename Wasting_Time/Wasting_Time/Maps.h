#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>



class Map
{
public:
	
	void PrintMap(std::string filepath)
	{
		std::ifstream infile(filepath);

		while (infile) //While not eof
		{
			//print out each character on the line and return to make the full map from a text file
			std::string strInput;

			std::getline(infile, strInput);

			std::cout << strInput << '\n';
		}
	}

private: 

	std::string fpath;
	
};