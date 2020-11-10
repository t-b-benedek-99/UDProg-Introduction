#include "std_lib_facilities.h"

namespace X
{
	int var = 1;
	void print()
	{
		cout << var << endl;
	}
}


namespace Y
{
	int var = 2;
	void print()
	{
		cout << var << endl;
	}
}


namespace Z
{
	int var = 3;
	void print()
	{
		cout << var << endl;
	}
}

int main()
{
	X::var = 7;
	X::print(); // print X’s var
	using namespace Y;
	var = 9;
	print(); // print Y’s var

	{
		using Z::var;
		using Z::print;
		var = 11;
		print(); // print Z’s var
	}

	print(); // print Y’s var
	X::print();
}