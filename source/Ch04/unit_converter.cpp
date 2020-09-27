#include "std_lib_facilities.h"

int main()
{
	/*
	double temp1;
	double temp2;

	while(cin >> temp1)
	{
		cin >> temp2;
		cout << temp1 << "\n" << temp2 << "\n";
		if(temp1 > temp2)
		{
			cout << "the smaller value is: " << temp2 << "\n";
			cout << "the larger value is: " << temp1 << "\n";
			if((temp1 - temp2) < 1.0/100)
			{
				cout << "the numbers are almost equal" << "\n";
			}
		}
		else if(temp2 > temp1)
		{
			cout << "the smaller value is: " << temp1 << "\n";
			cout << "the larger value is: " << temp2 << "\n";
			if((temp2 - temp1) < 1.0/100)
			{
				cout << "the numbers are almost equal" << "\n";
			}
		}
		else
		{
			cout << "the numbers are equal" << "\n";
		}
	}
	*/
	vector<double> distances;
	double temp;
	double largest = 0;
	double smallest = 100000000000;
	string unit;
	cout << "enter a value with a distance unit (in m, cm, in, ft)!" << "\n";
	while(cin >> temp)
	{		
		cin >> unit;
		while(unit != "m" && unit != "cm" && unit != "in" && unit != "ft"){
			cout << "please enter a value with a valid distance unit (in m, cm, in, ft)!" << "\n";
			cin >> temp >> unit;
		}
		// filling up the vector with distance values in meters
		if(unit == "m")
		{
			distances.push_back(temp);
		} else if(unit == "cm")
		{
			//1m == 100cm
			distances.push_back(temp/100);
		} else if(unit == "in")
		{
			//1in == 2.54cm
			//1cm == 1/100m
			distances.push_back((temp*2.54)/100);
		} else if(unit == "ft")
		{
			//1ft == 12in
			//1in == 2.54cm
			//1cm == 1/100m
			distances.push_back(((temp*12)*2.54)/100);
		}		
		cout << "the value entered: " << temp << "\n";
		cout << "the unit is: " << unit << "\n";
		if(temp > largest)
		{
			largest = temp;
			cout << "the largest so far" << "\n";
		}

		if(temp < smallest)
		{
			smallest = temp;
			cout << "the smallest so far" << "\n";
		}

	}

	sort(distances);

	double largestEver;
	double smallestEver = 100000000000;
	double sumOfValuesInDistances = 0;

	for(double x : distances)
	{
		sumOfValuesInDistances += x;
		cout << x << "\n";
		if(x > largestEver)
		{
			largestEver = x;
		}
		if(x < smallestEver)
		{
			smallestEver = x;
		}

	}

	cout << "The sum of the values entered: " << sumOfValuesInDistances << "\n";
	cout << "The smallest value entered: "  << smallestEver << "\n";
	cout << "The largest value entered: " << largestEver << "\n";

	return 0;
}