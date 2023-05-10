#include "date.h"
#include <format>

//Разпределяне на  памет за статичните константи-масиви
const int date::m_days[13]{ 0, 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
const std::string date::m_names[13]{ "", "януари", "февруари", "март", "април",
  "май", "юни", "юли", "август", "септември", "октомври",
   "ноември", "декември" };

void date::setDate(int d, int m, int y)
{
	//year - в диапазона 1900- 2050
	year = (y >= 1900 && y <= 2050) ? y : 2000;
	month = (m >= 1 && m <= 12) ? m : 1;
	if (month == 2 && isLeap()) {
		day = (d >= 1 && d <= 29) ? d : 1;
	}
	else {
		day = (d >= 1 && d <= m_days[month]) ? d : 1;
	}
}

bool date::isLeap() const
{
	return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);

}

//по-старата дата е по-малка
bool date::operator<(const date& second) const
{
	if (year < second.year) return true;

	if (year == second.year) {
		if (month < second.month) return true;
		else if (month == second.month) {
			if (day < second.day) return true;
		}
	}
	return false;

}

bool date::operator>(const date& second) const
{
	return !(*this < second);
}

bool date::operator<=(const date& second) const
{
	return *this < second || *this == second;
}

bool date::operator>=(const date& second) const
{
	return *this > second || *this == second;
}

bool date::operator==(const date& second) const
{
	return this->year == second.year
		&& this->month == second.month
		&& this->day == second.day;
}

bool date::operator!=(const date& second) const
{
	return  !(*this == second);
}

date::date()
{
	setDate(1, 1, 2000);
}

date::date(int d, int m, int y)
{
	setDate(d, m, y);
}

int date::get_day() const
{
	return day;
}

int date::get_month() const
{
	return month;
}

int date::get_year() const
{
	return year;
}

void date::set_day(int d)
{
	day = d;
}

void date::set_month(int m)
{
	month = m;
}

void date::set_year(int y)
{
	year = y;
}

std::string date::toString() const
{
	return std::format("{:d} {:s} {:d} г.", day,
		                      date::m_names[month], year);
}

std::string date::toShortString() const
{
	return std::format("{:0>2d}.{:0>2d}.{:>4d} г.", day, month, year);

}

std::ostream& operator<<(std::ostream& os, const date& dt)
{
	os << dt.toShortString();
	return os;
}

std::istream& operator>>(std::istream& is, date& dt)
{
	is >> dt.day >> dt.month >> dt.year;
	return is;
}
