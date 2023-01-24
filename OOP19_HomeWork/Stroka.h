#pragma once
#include <iostream>
//Task 2
class Stroka {
protected:
	char* str;
	int lenght;
public:

	//Constructors for default
	Stroka() : lenght{ 0 }, str{ nullptr } {};

	Stroka(char* receivingStr) : lenght{ int(strlen(receivingStr)+1) }, str{ new char[lenght] } {
		strcpy_s(str, strlen(receivingStr) + 1, receivingStr);
	}

	// Copy constructor
	Stroka(const Stroka& receivingObj) : Stroka(receivingObj.str) {
		lenght = receivingObj.lenght;
	}
	
	// Operator '='
	void operator = (const Stroka& receivingObj) {
		lenght = receivingObj.lenght;
		strcpy_s(str, strlen(receivingObj.str) + 1, receivingObj.str);
	}

	// Receiving lenght of str
	int getLenght() {
		return lenght;
	}

	// Clean str
	void cleanStr() {
		str = (char*)"\0";
	}

	// I don't fully understand what is difference between
	// the operators + and +=, in this class, in fact, thay work indentically:
	// that in the first a string is added to class's string, that in second.
	// That's why, operator + work with lenght and size

	char* operator += (char* receivingStr) {
		lenght += (int)strlen(receivingStr) + 1;
		strcat_s(str, lenght+1, receivingStr);
		return str;
	}

	int operator +(int receivingLenght) {
		lenght += receivingLenght;
		return lenght;
	}

	bool operator == (const Stroka& receivingObj) {
		if (strcmp(str, receivingObj.str) == 0)
			return 1;
		return 0;
	}

	bool operator != (const Stroka& receivingObj) {
		if (strcmp(str, receivingObj.str) == 0)
			return 0;
		return 1;
	}

	// Destructor
	~Stroka() {
		delete[] str;
	}
};

//Task 3

class BitStroka : public Stroka {
	// +0 - 0000000000
	// -0 - 1111111111
public:
	// Default constructors
	BitStroka() : Stroka() {};
	BitStroka(char* receivingStr) {
		if (check(receivingStr))
			Stroka(receivingStr);
	}

	// Check string| if it include in it not only '1' and '0'
	bool check(char* receivingStr) {
		bool flag = 1;
		for (int i = 0; i < strlen(receivingStr); i++) {
			if (receivingStr[i] != '0' || receivingStr[i] != '1') {
				flag = 0;
				Stroka((char*)"");
				break;
			}
		}
		if (flag)
			return 1;
		return 0;
	}

	// Copy constructor
	BitStroka(const BitStroka& receivingObj) : BitStroka(receivingObj.str) {
		lenght = receivingObj.lenght;
		strcpy_s(str, strlen(receivingObj.str) + 1, receivingObj.str);
	}

	// Operator '='
	void operator = (const BitStroka& receivingObj) {
		lenght = receivingObj.lenght;
		strcpy_s(str, strlen(receivingObj.str) + 1, receivingObj.str);
	}

	// Change number sign
	void tr_to_two_complement() {
		bool flag_pos = true;
		bool flag_neg = true;
		// If string is +0
		for (int i = 0; i < lenght; i++) {
			if (str[i] != '0') {
				flag_pos = false;
				break;
			}
		}
		// If string is -0
		if (!flag_pos) {
			for (int i = 0; i < lenght; i++) {
				if (str[i] != '1') {
					flag_neg = false;
					break;
				}
			}

		}
		// If string isn't +0 and isn't -0
		if (flag_pos == 0 && flag_neg == 0)
			_strrev(str);
	}

	// Add one number to other
	char* operator += (char* receivingStr) {
		char* buffStr = new char[125];

		//   1 1 1 1
		// + 0 1 0 1
		//  --------
		// 1 0 1 0 0
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

		lenght = strlen(buffStr);
		strcpy_s(str, strlen(buffStr)+1, buffStr);
		return str;
	}

	// lenght+lenght
	int operator +(int receivingLenght) {
		lenght += receivingLenght;
		return lenght;
	}



	// Destructor
	~BitStroka() {
		delete[] str;
	}

};