#include "std_lib_facilities.h"

struct Point {
	double x;
	double y;
	Point(int x, int y): x(x), y(y) {};
};

vector<Point> original_points;
vector<Point> processed_points;

void request_input()
{
	cout << "Please enter 7 points: (x,y)" << endl;
	for (int i = 0; i < 7; ++i)
	{
		int currentX, currentY;
		cin >> currentX >> currentY;
		original_points.push_back(Point(currentX,currentY));
	}
}

void write_output()
{
	string oname = "mydata.txt";
	ofstream ost {oname};
	if (!ost) error("can't open output file ",oname);

	for (Point p : original_points)
		ost << '(' << p.x << ',' << p.y << ')' << endl;

	ost.close();
}

void read_file()
{
	string iname = "mydata.txt";
	ifstream ist {iname};
	if(!ist) error("can't open input file ", iname);

	char open_brace, comma, close_brace;
	for (int myX, myY; ist >> open_brace >> myX >> comma >> myY >> close_brace; )
	{
		processed_points.push_back(Point(myX, myY));
	}

	ist.close();
}

void compare_vectors()
{
	if(original_points.size() != processed_points.size()) error("Something's wrong!");
	for(long unsigned int i = 0; i < original_points.size(); ++i)
	{
		if(original_points[i].x != processed_points[i].x) error("Something's wrong!");
		if(original_points[i].y != processed_points[i].y) error("Something's wrong!");
	}

	cout << "The size of the vectors are the same" << endl
		 << "original_points.size(): " << original_points.size() << endl
		 << "processed_points.size(): " << processed_points.size() << endl;
}

int main()
{
	request_input();

	write_output();

	read_file();
	
	for(Point p : processed_points)
		cout << '(' << p.x << ',' << p.y  << ')' << endl;

	compare_vectors();

	return 0;
}