#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to\n";
	string first_name = "";
	cin >> first_name;
	cout << "Dear, " << first_name << "!\n";
	cout << "\tHow are you? I am fine. I miss you. I wish we could meet and go to the cinema tomorrow.\n";

	string friend_name = "";
	cout << "Enter the name of another friend of yours\n";
	cin >> friend_name;

	char friend_sex = 0;

	cout << "Please tell the gender of " << friend_name << "!\n";
	cout << "Type m for male, f for female\n";
	cin >> friend_sex;

	if(friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";

	if(friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";

	int age = 0;

	cout << "Please tell the age of the recipient!\n";
	cin >> age;

	cout << "I hear you just had a birthday and you are " << age << " years old.\n";

	if(age <= 0 || age >= 110)
		simple_error("you're kidding!");

	if(age < 12)
		cout << "Next year you will be " << age+1 << "\n";

	if(age == 17)
		cout << "Next year you will be able to vote.\n";

	if(age > 70)
		cout << "I hope you are enjoying retirement.\n";

	cout << "Yours sincerely,\n\n";
	cout << "Benedek\n";

	return 0;
}