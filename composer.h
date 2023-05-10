#pragma once
#include <string>
#include <vector>
#include "date.h"
class Composer {
private:
	std::string name;
	date bdate;
	std::string country;
	std::vector<std::string> work;
public:
	//con
	Composer();
	Composer(std::string _name, date _date, std::string _country, std::vector<std::string> _work);
	//set() get()
	std::string getName() const;
	std::string getLastName() const;
	void setName(std::string newName);
	std::vector<std::string> getWork() const;
	std::string getWork(int index) const;
	void setWork(int index, std::string value);

	//toString	
	std::string toString() const;

	//add
	void addWork(std::string wName);
	int getWorkCount() const;

	bool operator<(const Composer& second) const;
	bool operator>(const Composer& second) const;

	friend std::ostream& operator<<(std::ostream& os, const Composer& obj);

};