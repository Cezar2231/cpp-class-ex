#pragma once
#include <string>
#include <iostream>
class date {
private:
	int day;
	int month;
	int year;

	void setDate(int d, int m, int y);
	bool isLeap() const;

	static const int m_days[13];
	static const std::string m_names[13]; 



public:
	//Предефинирани операции за сравнение

	bool operator<(const date& second)const;
	bool operator>(const date& second) const;

	bool operator<=(const date& second)const;
	bool operator>=(const date& second) const;

	bool operator==(const date& second) const;
	bool operator!=(const date& second) const;

	//конструктори
	date();
	date(int d, int m, int y);

	//getters
	int get_day() const;
	int get_month() const;
	int get_year() const;

	//setters
	void set_day(int d);
	void set_month(int m);
	void set_year(int y);

	std::string toString() const;
	std::string toShortString() const;



	friend std::ostream& operator<<(std::ostream& os, const date& dt);
	friend std::istream& operator>>(std::istream& os, date& dt);
};
