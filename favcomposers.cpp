#include <iostream>
#include "favcomposers.h"
#include "date.h"
#include <vector>
#include <algorithm>
#include <string>
#include<set>
FavComposer::FavComposer(){

}

FavComposer::FavComposer(std::string _name, int _FavCount, std::vector<Composer> _FavComposers):
	name(_name),FavCount(_FavCount),FavComposers(FavComposers) {
	this->name = _name;
	this->FavCount = _FavCount;
	this->FavComposers = _FavComposers;
}

std::string FavComposer::get_name() const
{
	return name;
}


void FavComposer::input() {
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Favorite composers count: ";
	std::cin >> FavCount;
	std::cout << std::endl;
	for (int i = 0; i < FavCount; i++) {
		std::string newC;
		std::cout << "Enter your Favourite Name composers: ";
		std::cin >> newC;
		std::cout << "Enter your Favourite Date composers: ";
		date d;
		std::cin >> d;
		std::cout << "Enter your Favourite coutry composers: ";
		std::string c;
		std::cin >> c;
		std::string composition;
		std::cout << "Enter your Favourite cimposition composers: ";
		std::cin >> composition;
		Composer comp(newC, d, c, std::vector<std::string> {composition});
		FavComposers.push_back(comp);
	}
	std::cout << std::endl;
}

void FavComposer::lastNameSeach(std::string l_name){
	//find_if
}

void FavComposer::yobSort(const FavComposer& c1, const FavComposer& c2){
	//begin end
}

void FavComposer::AddFavComposer(Composer c,std::string newFav){
	//FavComposers.push_back(c,newFav);
}

std::ostream& operator<<(std::ostream& os, const FavComposer& obj){

	os << "Name: " << obj.name << std::endl;
	std::cout << std::endl;

	return os;
}
