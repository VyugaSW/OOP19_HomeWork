#pragma once
#include <iostream>
//Task 1

class Pet {
protected:
	char* name;
	int age;

	Pet(char* n, int a) : name{ new char[strlen(n) + 1] }, age{ a } 
	{ 
		strcpy_s(name, strlen(n) + 1, n); 
	}
};


class Cat : public Pet {
	char* species;
	char* wool_color;
	char* eyes_color;
public:

	Cat(char* n, int a, char* s, char* wC, char* eC) : Pet(n, a),
		species{ new char[strlen(s) + 1] }, wool_color{ new char[strlen(wC) + 1] }, eyes_color{ new char[strlen(eC) + 1] }
	{
		strcpy_s(species, strlen(s) + 1, s);
		strcpy_s(wool_color, strlen(wC) + 1, wC);
		strcpy_s(eyes_color, strlen(eC) + 1, eC);
	}


};


class Dog : public Pet {
	char* species;
	char* wool_color;
	int tail_long;
public:

	Dog(char* n, int a,char* s, char* wC, int tL) : Pet(n, a),
		species{ new char[strlen(s) + 1] }, wool_color{ new char[strlen(wC) + 1] }, tail_long{ tL }
	{
		strcpy_s(species, strlen(s) + 1, s);
		strcpy_s(wool_color, strlen(wC) + 1, wC);
	};


};

class Parrot : public Pet {
	char* species;
	char* color;
	int vocabular;
public:

	Parrot(char* n, int a, char* s, char* ñ, int v) : Pet(n, a),
		species{ new char[strlen(s) + 1] }, color{ new char[strlen(ñ) + 1] }, vocabular{ v }
	{
		strcpy_s(species, strlen(s) + 1, s);
		strcpy_s(color, strlen(ñ) + 1, ñ);
	};


};