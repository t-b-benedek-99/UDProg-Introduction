#include "std_lib_facilities.h"

struct Person {
	string last_name;
	string first_name;
	long int telephone_number;
	string email_address;

	Person(string lname, string fname, long int phone, string email): last_name{lname}, first_name{fname}, telephone_number{phone}, email_address{email}
	{}

	void print_person_data();
};

void Person::print_person_data()
{
	cout << setw(14) << last_name << ',' << setw(20) << first_name << '|' << setw(18)
		<< telephone_number << '|' << email_address << endl;
}

int birth_year = 1999;

int my_age = 21;

int main()
{
	cout << showbase << birth_year << "\t(decimal)\n"
		<<  hex << birth_year << "\t(hexadecimal)\n"
		<< oct << birth_year << "\t(octal)\n";

	cout << dec << my_age << endl;

	int a, b, c, d;

	cin >> a >>oct >> b >> hex >> c >> d;
	cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;

	double num = 1234567.89;

	cout << dec
		<< defaultfloat << num << '\t'
		<< fixed << num << '\t'
		<< scientific << num << endl;

	Person me = Person("Tóth", "Bálint Benedek", 36302733619, "toth.balint.benedek@gmail.com");
	Person Gyozi = Person("Kis", "Győző", 36709876543, "gyozike@gmail.com");
	Person Gabi = Person("Nagy", "Gábor", 36717654321, "gabeszk@gmail.com");
	Person Ancsa = Person("Horváth", "Anna", 36701234567, "hanna@gmail.com");
	Person Viki = Person("Hekula", "Viki", 36307654321, "viki@gmail.com");
	Person Olga = Person("Mészáros", "Olga", 36301234567, "molgica@gmail.com");

	me.print_person_data();

	Gyozi.print_person_data();

	Gabi.print_person_data();

	Ancsa.print_person_data();

	Viki.print_person_data();

	Olga.print_person_data();

	return 0;
}