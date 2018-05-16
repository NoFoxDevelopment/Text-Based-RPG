#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>

//using statements for long declarations
using std::this_thread::sleep_for;
using std::chrono::milliseconds;


class Text
{
public:
	
	Text(std::string fpath, int milliseconds) :
		path(fpath), pausePerCharacter(milliseconds)
	{
		
	}

	Text()
	{

	}

	void textOutPut(std::string fpath)
	{
		//char c;
		infile.open(fpath);

		while (infile.is_open())
		{

			while (std::getline(infile, message))
			{
				for (const char c : message)
				{
					std::cout << c << std::flush;
					sleep_for(milliseconds(pausePerCharacter));
				}

				std::cout << '\n';
			}

			infile.close();
		}

	}

private:

	std::ifstream infile;
	std::string path;
	std::string message;
	int pausePerCharacter;

};