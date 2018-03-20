#include<iostream>
#include "other.h"
class GAME {
private:
	int _mode, _level;
public:
	//Ask user are they want to play
	bool Start_or_End() {
		std::cout << "Do you want to start a game\nWant press S Don't want press N\n";
		char conmand ;
		bool first = true;;
		do {
			if (!first)
				std::cout << "error\n";
			std::cin>>conmand;
			
			first = false;
		} while (conmand != 's' && conmand != 'S' && conmand != 'n' && conmand != 'N');
		if (conmand == 's' || conmand == 'S')
			return true;
		return false;
	}
	void Choice_mode() {
		std::string conmand;
		std::cout << "Choice mode\n1.single player 2.multiple player 3.with computer player\n";
		bool first = true;
		do {
			if (!first)
				std::cout << "error\n";
			std::cin.ignore();
			getline(std::cin,conmand);
			first = false;
		} while (!Legal_int(conmand, 1));
		_mode = String_to_int(conmand);
	}
	int Mode() {
		return _mode;
	}
	int Choice_level() {
		std::string conmand;
		std::cout << "please enter computer player level.(1-4)\n";
		bool first = true;
		do {
			if (!first)
				std::cout << "error\n";
			getline(std::cin,conmand);
			first = false;
		} while (!Legal_int(conmand, 1) || conmand < "1" || conmand > "4");
		_level = String_to_int(conmand);
	}
};