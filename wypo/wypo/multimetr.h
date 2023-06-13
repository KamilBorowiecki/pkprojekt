#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Warehouse.h"


class Multimetr:public Warehouse
{
public:
	std::string brand;
	double price;
	std::string model;
	double weight;
	/*std::vector <Multimetr> tabMult;*/
	Multimetr* tabMult; 
	int size;
	static int count;
	int number;

	Multimetr();
	Multimetr(int size);
	Multimetr(const std::string& brand, double price, std::string model, double weight);
	~Multimetr();


	void add(const Multimetr& obj);
	void show() override;
	std::string eqAddmodel(int number);
	std::string eqAddbrand(int number);
	int getNumber();
	int chooseNr();

	/*void  read(Multimetr obj);*/
	friend std::ostream& operator <<(std::ostream& s, const Multimetr&);
};
