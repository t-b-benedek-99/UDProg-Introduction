#include "std_lib_facilities.h"

const vector<string> months =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"November",
	"December"
};

enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Date{
	int year;
	Month month;
	int day;
public:
	class Invalid {};
	Date(int y, Month month, int d): year(y), month(month), day(d) { if(!is_valid()) throw Invalid{};}
	bool is_valid();
	void add_day(int n);
	int get_year() { return year; }
	Month get_month() { return month; }
	int get_day() { return day; }
};

bool Date::is_valid()
{
	if (year < 0 || day < 1 || day > 31) return false;

	return true;
}

/*
Date::Date(int y, int m, int d)
{
	if (y > 0)
		year = y;
	else
		error("Invalid year");
	if (m <= 12 && m > 0)
		month = m;
	else
		error("Invalid month");
	if (d > 0 && d <= 31)
		day = d;
	else
		error("Invalid day");
}
*/

void Date::add_day(int n)
{
	day += n;
	if(day > 31)
	{
		++month;
		day -= 31;
		if(month == Month::jan)
		{
			year++;
		}
	}
}

int main()
try {

	Date today {1978, Month::jun, 25};

	cout << "Date: " << today.get_year() << ". "
		<< today.get_month() << ' ' << today.get_day() << ".\n";
	
	Date tomorrow {today};
	tomorrow.add_day(1);
	
	cout << "Date: " << tomorrow.get_year() << ". "
		<< tomorrow.get_month() << ' ' << tomorrow.get_day() << ".\n";

	return 0;
} catch(Date::Invalid& e){
	cerr << "Invalid date" << endl;
	return 1;
} catch(exception& e){
	cerr << e.what() << endl;
	return 2;
} 