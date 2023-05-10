#include <iostream>
#include "composer.h"
#include <vector>
#include "date.h"
#include "favcomposers.h"
using namespace std;
int main() {
	system("chcp 1251>0");
	Composer c1;
	cout << c1.toString() << endl;
	c1.addWork("No 1 Latin");
	c1.addWork("In Memorial");
	cout << c1.toString() << endl;
	cout << "Compositor full name: " << c1.getName() << endl;
	cout << "Compositions count: " << c1.getWorkCount() << endl;

	c1.setName("Gabriela Montero");
	c1.setWork(0, "eX Patricia");
	cout << c1.toString() << endl;
	c1.getWork();;
	Composer c2("Dobrinka Tabakova", date(12, 1, 1980), "Bulgaria", { "Praise" });
	cout << c2.toString() << endl;
	cout <<"Compositor last name: " << c2.getLastName() << endl;

}