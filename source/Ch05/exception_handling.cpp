#include "std_lib_facilities.h"

int main()
try {
	// Error 1:
	// The problem was 'Cout' with a capital C starting letter
	// the fixed version is:
	//cout << "Success!\n";

	// Error 2:
	// The problem was 'error: missing terminating' according to the compiler
	// there were no ';' character at the end of the line
	// the fixed version is:
	//cout << "Success!\n";

	// Error 3:
	// The problem was 'exception_handling.cpp:14:24: error: stray ‘\’ in program'
	// according to compiler
	// meaning that there was no starting " sing of the string literal
	// and there was another problem: 'error: missing terminating " character'
	// meaning that we didn't have a ';' line ending character.
	// the fixed version is:
	//cout << "Success" << "!\n";

	// Error 4:
	// We received a compiler error: 'error: ‘success’ was not declared in this scope'
	// it was triggered because of the lack of "" (double quotes) for declaring string literal
	// the right way to pass a string literal to cout is:
	// cout << "success" << '\n';
	// but if we would like to write: "Success!" exactly, then the correct solution will be:
	// cout << "Success!" << '\n';

	// Error 5:
	// The code was not properly indented, but it's just an issue of apperance
	// the main issue was that we tried to assign an int value to a string, which is illegal
	// and after that we tried to put this illegal string to an int vector
	// we cannot assign put a string into an int vector, it is a type error
	// The improved, working solution is:
	//int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
	// but we should intend it to separate lines, like this:
	// Just to get a prettier code:
	/*
	int res = 7;
	vector<int> v(10);
	v[5] = res;
	cout << "Success!\n";
	*/

	// Error 6:
	// The main issue (the compile time error) is that the vector's 5th element is not accessed correctly
	// We should use v[5] instead of v(5), so the problem is the use of braces
	// this fix compiles just fine here:
	// vector<int> v(10); v[5] = 7; if (v[5]!=7) cout << "Success!\n";
	// but this above code contains a logic error
	// we never receive "Success" on the screen, since the condition
	// is never met
	// so we should reconstruct our solution, something just like this:
	// vector<int> v(10); v[5] = 7; if (v[5]==7) cout << "Success!\n";
	// but we shouldn't forget about the right indent:
	// so the final solution will be:
	/*
	vector<int> v(10);
	v[5] = 7;
	if (v[5]==7)
		cout << "Success!\n";
	*/

	// Error 7:
	// We got a compile time error: "error: ‘cond’ was not declared in this scope"
	// because the cond variable doesn't exist, it was never created
	// so we need to create it, and make sure to assign it a true value
	// in order to avoid a semantic error
	// the solution is:
	//bool cond = 1;
	//if (cond) cout << "Success!\n"; else cout << "Fail!\n";
	// but we should indent our code as always
	// so the final solution wull be:
	/*
	bool cond = 1;
	if (cond)
		cout << "Success!\n";
	else
		cout << "Fail!\n";
	*/

	// Error 8:
	// The main problem is a logic error
	// The code compiles and runs fine
	// But we receive "Fail!" instead of a "Succcess!" on the screen
	// we should initialize the c bool variable to true:
	//bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
	// but here our code looks ugly
	// we should indent it properly:
	/*
	bool c = true;
	if (c)
		cout << "Success!\n";
	else
		cout << "Fail!\n";
	*/

	// Error 9:
	// We got a compiler error
	// We have multiple issues here:
	// first we created a variable of type "boo" which here does not exit
	// probably we wanted a bool type, but if so
	// then we had a logic error, since the word "fool" is longer than
	// the word "ape", so if we want our bool to be true
	// we need to either swap the values or replace the
	// relation sign from this "<" to this: ">"
	// the fixed version here:
	//string s = "ape"; bool c = "fool">s; if (c) cout << "Success!\n";


	// Error 10:
	// We got a logic error here:
	// the two strings doesn't equal, so we never write out success
	// maybe we should change the "==" equals check to a "!=" sign
	// the fixes solution here:
	//string s = "ape"; if (s!="fool") cout << "Success!\n";
	// we should separate the lines, something like this:
	/*
	string s = "ape";
	if (s!="fool")
		cout << "Success!\n";
	*/

	// Error 11:
	// Compile time error
	// The main mistake was the use of "<" instead of "<<" operator
	// so this code compiles and runs fine:
	//string s = "ape"; if (s=="fool") cout << "Success!\n";
	// but here we still got a logic error
	// since success will be never on the screen
	// to fix this, make sure to meet the condition
	// the final solution here:
	/*
	string s = "ape";
	if (s != "fool")
		cout << "Success!\n";
	*/
	
	// Error 12:
	// We got compiler errors:
	// first we need to remove "+" sign and replace it with
	// a logic operator, like "<" or ">" or "==" or "!="
	// to meet the condition we need to use "<" sign
	// and we need to replace "cout <" to "cout <<"
	// the fixes solution here:
	/*
	string s = "ape";
	if (s<"fool")
		cout << "Success!\n";
	*/

	// Error 13:
	// The code compiles and runs fine
	// The problem we have is a logic error
	// We got into an infinite loop
	// since at the for loop we used "0<v.size()" as a condition
	// which of course will always be false
	// the solution is to use the variable "i" in the condition
	// so the final solution is here:
	/*
	vector<char> v(5);
	for (int i=0; i<v.size(); ++i) ; cout << "Success!\n";
	*/

	// Error 14:
	// this compiles and runs just fine
	// we receive the output excepted, we get the "Success!" on our screen
	// though it has a logic error, which could break everything
	// we iterate through the loop with "<=" which means
	// we could try to access an element of the vector which
	// is not in the range
	// so to fix this we should always only iterate on
	// the vector like this:
	/*
	vector<char> v(5);
	for (int i=0; i<v.size(); ++i) ;
		cout << "Success!\n";
	*/

	// Error 15:
	// the code compiles and runs well
	// but there is a logic error, since we got "Succes" on the screen
	// rather then "Success!\n" which is excepted
	// to fix this we need to iterate on the entire string
	// this version works fine:
	/*
	string s = "Success!\n";
	for (int i=0; i<s.size(); ++i)
		cout << s[i];
	*/

	// Error 16:
	// We got a compiler error, since there is no need to 
	// use "then" after an if statement, since no such keyword exists
	// in the current language and context
	// the working version here is this:
	/*
	if (true)
		cout << "Success!\n";
	else
		cout << "Fail!\n";
	*/

	// Error 17:
	// The program compiles and runs just fine
	// Though we cannot see any message on the screen
	// So it contains a logic error:
	// the root cause of the issue is that
	// the int-to-char conversion is type unsafe
	// and it comes out when we try to put a too big int to a char
	// which the char cannot hold
	// the fix is here:
	/*
	int x = 1;
	char c = x;
	if (c==1)
		cout << "Success!\n";
	*/

	// Error 18:
	// The code compiles and runs just fine
	// Even the output seems right
	// Though the issue is:
	// We shouldn't iterate through a string by a value (10)
	// but we should get the exact size of that string literal
	// besides, the code was not indented properly
	/*
	string s = "Success!\n";
	for (int i=0; i<s.size(); ++i)
		cout << s[i];
	*/

	// Error 19:
	// We got a compiler error
	// Since we haven't declared a data type for vector to hold
	// the fix is here:
	//vector<int> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
	// this above code works fine, but we shouldn't iterate through
	// by "<=" but we should use "<":
	// so the final fix is here:
	/*
	vector<int> v(5);
	for (int i=0; i<v.size(); ++i) ;
		cout << "Success!\n";
	*/

	// Error 20:
	// common logic error is here:
	// we are incrementing j and the condition is about i
	// so we have to make sure to increment the right variable
	// something just like this:
	/*
	int i=0;
	int j = 9;
	while (i<10) ++i;
	if (j<i)
		cout << "Success!\n";
	*/

	// Error 21:
	// we have a compile time error
	// because we tried to divide by zero
	// since x = 2 and x-2 = 0
	// so the double d has an illegal value
	// we should replace it with some other
	// valid expression
	// besides we should modify the condition in the if statement
	// and then we need to change int x type to be type of double
	// here goes the solution:
	/*
	double x = 2;
	double d = 5/x;
	if (d==(x+0.5))
		cout << "Success!\n";
	*/

	// Error 22:
	// We received a compile time error
	// since we don't have to say the data type of string
	// a string is always a string of char values, so string<char> is illegal
	// therefore the fix is:
	/*
	string s = "Success!\n";
	for (int i=0; i<=10; ++i)
		cout << s[i];
	*/

	// Error 23:
	// We have compile time error:
	// The first issue is simple, we forgot to declare and initialize
	// the variable j, so it does not exit in the context
	// besides in the while loop we are incrementing the wrong variable
	// so either we should use j as a control variable
	// or we should increment i instead
	// the fix is here:
	/*
	int i=0;
	int j = 9;
	while (i<10) ++i;
	if (j<i)
		cout << "Success!\n";
	*/

	// Error 24:
	// We received multiple compile time errors:
	// first logic error here is:
	// we should declare x as double instead of an int
	// to get the precise value of the division in the initializiaton
	// of the double d variable
	// then we need to repair the condition in the if statement
	// since "=" doesn't mean the same as "=="
	// so we should use the "==" equals check
	// and we need to repair the condition to be met
	// something just like this:
	/*
	double x = 4;
	double d = 5/(x-2);
	if (d==((x/2)+0.5)) 
		cout << "Success!\n";
	*/

	// Error 25:
	// cin is for standard input stream
	// when we are willing to output something
	// we need to use cout instead of cin
	// the fixes goes here:
	cout << "Success!\n";

	return 0;
} catch(exception& e){
	cerr << "error: " << e.what() << '\n';
	return 1;
} catch(...){
	cerr << "Oops: unknown exception!\n";
	return 2;
}