#include<iostream>

class GUESS {
private:
	std::string _name[9];
	int _guess[9];
	int _num;// how many players
	int _now;//whitch player play now
	bool _have_start;
public:
	void Build_no_com() {
		bool repeat;
		for (int num = 1; num <= _num; num++) {
			std::cout << "please enter player " << num << " name>\n";
			repeat = false;
			do {
				if (repeat) {
					std::cout << "Sorry! This name has already had. Please enter again.\n";
					repeat = false;
				}
				getline(std::cin, _name[num - 1]); // 0-8
				for (int i = 0; i < num - 1; i++) {
					if (_name[num - 1] == _name[i]){
						repeat=true;
						break;
					}
				}
			}while(repeat);
		}
	}
	void Build() {
		bool first = true;
		std::cout << "please enter player 1 name>\n";
		do {
			if (!first)
				std::cout << "Sorry! you can't name \"computer player\"\n";
			getline(std::cin, _name[0]);
			first = false;
		} while (_name[0] == "computer player");
		_name[1] = "computer player";
	}
	void Advanced(int mode) {
		std::string num;
		bool first = true;
		switch (mode) {
		case 1:
			_num = 1;
			break;
		case 2:
			std::cout << "please enter how many players?\n";
			do {
				if (!first)
					std::cout << "error! only 2-9 people.\n";
				getline(std::cin, num);
				first = false;
			} while (!Legal_int(num, 1) || num < "2" || num > "9");
			_num = String_to_int(num);
			break;
		case 3:
			_num = 2;
			break;
		}
	}
	int Guess_no_com(){
		if(!_have_start){
			std::cout<<"Game start.\nPlease guess password\n";
			_have_start=false;
		}
		std::string temp;		
		bool legal=true;
		std::cout<<_name[_now]<<"\n";
		do {
			if (!legal)
				std::cout << "error\n";
			legal=true;
			getline(std::cin,temp);
			if(!Legal_int(temp,4)){
				legal=false;
				continue;
			}
			if(repeat(temp)){
				legal=false;
				continue;
			}
		} while (!legal);
	}
};