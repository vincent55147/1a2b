
#include<iostream>
#include <ctype.h>
bool Legal_int(std::string a, int num) {
	if (a.size() != num)
		return false;
	for (int i = 0; i < num; i++)
		if (!isdigit(a[i]))
			return false;
	return true;
}

int String_to_int(std::string a) {
	int num = 0, digits = 1;
	for (int i = a.size() - 1; i >= 0; i--) {
		num += (a[i] - '0') * digits;
		digits *= 10;
	}
	return num;
}

bool repeat(std::string thing){
	for(int i=0;i<thing.size();i++)
		for(int h=i+1;h<thing.size();h++)
			if(thing[i]==thing[h])
				return true;
	return false;
}
