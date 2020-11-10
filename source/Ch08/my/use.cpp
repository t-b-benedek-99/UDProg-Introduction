#include "my.h"

int foo;

int main()
{
	foo = 7;
	print_foo();
	print(99);

	int x = 7;
	int y = 9;

	// By value

	// It compiles but doesn't effect the original variables
	// Has no effect to the variables
	/*
	swap_v(x,y);
	swap_v(7,9);
	const int cx = 7;
	const int cy = 9;
	// It gets compiled, but has no effect to to cx and cy variables, since they're consts
	swap_v(cx,cy);
	swap_v(7.7,9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);
	swap_v(7.7,9.9);
	*/

	// With &

	// With reference it doesn't work
	/*
	print(x);
	print(y);
	swap_r(x,y);
	print(x);
	print(y);
	//swap_r(7,9); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	const int cx = 7;
	const int cy = 9;
	//swap_r(cx,cy); // compile time error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
	//swap_r(7.7,9.9); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	double dx = 7.7;
	double dy = 9.9;
	swap_r(dx,dy); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	swap_r(7.7,9.9); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	*/

	// With const&
	/* With using cont& it doesn't seem to work

	// It doesn't swap the values
	//swap_cr(x,y);

	// It doesn't have any effect
	swap_cr(7,9);
	const int cx = 7;
	const int cy = 9;
	// It doesn't swap the values
	swap_cr(cx,cy);
	// It have also no effect
	swap_cr(7.7,9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_cr(dx,dy);
	swap_cr(7.7,9.9);
	*/

	return 0;
}