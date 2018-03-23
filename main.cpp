#include "library.h"
PASSWORD password;
GAME game;
GUESS guess;
int main() {
	while (game.Start_or_End()) {
		password.Build();
		game.Choice_mode();
		switch (game.Mode()) {
		case 1:
			guess.Advanced(1);
			guess.Build_no_com();
			break;
		case 2:
			guess.Advanced(2);
			guess.Build_no_com();
			break;
		case 3:
			guess.Advanced(3);
			game.Choice_level();
			guess.Build();
			break;
		}
		do {
			switch (game.Mode()) {
			case 1:
			case 2:
				guess.Guess_no_com();
				break;
			case 3:
				break;
			}
		}while(password.End());
	}
}