
#include <iostream>

//Task 1
#include "Pet.h"

//Task 2 and Task 3
#include "Stroka.h"



int main()
{
	int lenght = 10;
	char* str = new char[lenght];
	strcpy_s(str, 10, "101101101");
	char* receivingStr = new char[5];
	strcpy_s(receivingStr, 10, "1111");
	char* buffStr = new char[lenght];

	int ones = 0;

	for (int i = 0; i < lenght; i++) {
		if (receivingStr[i] == '0' || receivingStr[i] == '1') {
			if (receivingStr[i] == '1' && str[i] == '1' && ones == 0) {
				ones = 1;
				buffStr[i] = '0';
			}
			else if (receivingStr[i] == '1' && str[i] == '0' && ones == 0) {
				buffStr[i] = '0';
			}
			else if (receivingStr[i] == '0' && str[i] == '0' && ones == 0) {
				buffStr[i] = '0';
			}
			else if (receivingStr[i] == '0' && str[i] == '0' && ones == 1) {
				ones = 0;
				buffStr[i] = '1';
			}
			else if (receivingStr[i] == '1' && str[i] == '1' && ones == 1) {
				buffStr[i] = '1';
			}
			else if (receivingStr[i] == '1' && str[i] == '0' && ones == 1) {
				buffStr[i] = '0';
			}
		}
		else {
			if (str[i] == '0' && ones == 0) {
				buffStr[i] = '0';
			}
			else if (str[i] == '0' && ones == 1) {
				ones == 0;
				buffStr[i] = '1';
			}
			else if (str[i] == '1' && ones == 1) {
				buffStr[i] = '0';
			}
		}
	}

}

