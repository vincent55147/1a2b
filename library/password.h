#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <time.h>
class PASSWORD {
private:
	int _password[4];
public:
	void Build() {
		//Check what numbers are used
		bool had[10];
		memset(had, false, 10);
		int temp, done = 0;
		srand(time(NULL));
		//create password
		while (done < 4) {
			temp = rand() % 9 + 1;
			if (!had[temp]) {
				had[temp] = true;
				_password[done++] = temp;
			}
		}
	}
	
};