//Modify the example of an STL set given in Sect. 8.3.2 so that the coordinates of
//the point are now given by double precision floating point variables.You will now
//need to think a bit more carefully about what it means for two coordinates to be
//equal : see the tip on comparing two floating point numbers given in Sect. 2.6.5.

#include <iostream>
#include <set>

class Point2d
{
public:
	double x, y;
	Point2d(double a, double b) : x(a), y(b) {}
	bool operator<(const Point2d& other) const
	{
		if (x < other.x)
			return true;
		else if (x > other.x)
			return false;
		else if (y < other.y)
			return true;
		else
			return false;
	}
};

int main(int argc, char* argv[])
{
	std::set<Point2d> points;
	Point2d origin(0.0, 0.0);
	points.insert(origin);
	points.insert(Point2d(-2, 1));
	points.insert(Point2d(-2, -5));
	points.insert(Point2d(1.0, 1));
	points.insert(Point2d(1, 1.0));
	points.insert(Point2d(0.0, 0.0));

	std::cout << "Number of points in set = " << points.size() << "\n";

	for (std::set<Point2d>::const_iterator c = points.begin(); c != points.end(); c++)
		std::cout << c->x << " " << c->y << "\n";


	std::cin.get();
	return 0;
}