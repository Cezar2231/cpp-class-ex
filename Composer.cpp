#include <iostream>
#include "composer.h"
#include <vector>
#include "date.h"

Composer::Composer() {
	this->name = "Gabriela Monteroo";
	this->bdate = { 31,3,1970 };
	this->country = "Venezuela";
} 

Composer::Composer(std::string _name, date _date, std::string _country, std::vector<std::string> _work) :
	name(_name),bdate(_date), country(_country), work(_work) {

	this->name = _name;
	this->bdate = bdate;
	this->country = _country;
	this->work = _work;
}

std::string Composer::getName() const {
	return name;
}
std::string Composer::getLastName() const {
	return name.substr(name.find(' ') + 1);
}
void Composer::setName(std::string newName) {
	name = newName;
}

std::vector<std::string> Composer::getWork()const {
	return work;
}

std::string Composer::getWork(int index)const {
	if (index >= 0 && index < work.size()) return work[index];
	else {
		std::cout << "There is no work with index " << index << std::endl;
		return "";
	}
}

void Composer::setWork(int index, std::string value) {
	if (index >= 0 && index < work.size()) {
		work[index] = value;
	}
	else {
		std::cout << "There is no work with index " << index << std::endl;
	}
}

//toString
std::string Composer::toString()const {
	std::string res ="Name: "+ name + ", " +" From: " + country + ", "+"Born in: "+ bdate.toShortString()+", " + " Compositions: ";
	std::string work_string = "";
	for (auto el : work)work_string += el + ", ";
	return res + work_string;
}

//add
void Composer::addWork(std::string Wname) {
	work.push_back(Wname);
}

int Composer::getWorkCount() const {
	return work.size();
}

// comparison by name
bool Composer::operator<(const Composer& second) const {
	return this->name < second.name;
}

bool Composer::operator>(const Composer& second) const {
	return !(*this < second);
}
std::ostream& operator<<(std::ostream& os, const Composer& obj) {
	os << "Name: " << obj.name << "\n", "Compositions: ";
	std::string separator;

	for (int i = 0; i < obj.work.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << obj.work[i];
	}
	std::cout << std::endl;

	return os;
}
