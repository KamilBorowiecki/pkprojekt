#pragma once
#include "GeneratorArbitralny.h"

class Rent
{
public:
	std::vector <std::string> base;
	int size;
	std::string sinceData;
	std::string untilData;
	std::string person;


public:
	Rent();
	Rent(const std::string& person, const std::string& sinceData, const std::string& untilData);
	~Rent();
	void add();
	void show();
	void deletePerson(int k);
	std::vector<std::string> names();
	std::string personAdd();
	std::vector<std::string> getbase();
	void setbase();
	int choosenr();

	friend std::ostream& operator<<(std::ostream& os, const Rent& o);
};