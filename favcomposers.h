#pragma once
#include <string>
#include "composer.h"
#include <vector>

class FavComposer {
private:
	std::string name;
	int FavCount;
	std::vector<Composer> FavComposers;
public:
	//con
	FavComposer();
	FavComposer(std::string _name, int _FavCount, std::vector<Composer> _FavComposers);
	std::string get_name()const;
	//input
	void input();
	friend std::ostream& operator << (std::ostream& os, const FavComposer& obj);
	void AddFavComposer(Composer c,std::string newFav);
	void lastNameSeach(std::string l_name);
	void yobSort(const FavComposer& c1, const FavComposer& c2);
	
	

};