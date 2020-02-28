#include <iostream>
using namespace std;

int main()
{
	double x1, y1;
	double x2, y2;
	double r1, r2;

	cout << "Enter coordinate x for the first center: ";
	cin >> x1;
	cout << "Enter coordinate y for the first center: ";
	cin >> y1;
	cout << "Enter coordinate x for the second center: ";
	cin >> x2;
	cout << "Enter coordinate y for the second center: ";
	cin >> y2;

	cout << "Enter radius for the first circle: ";
	cin >> r1;
	cout << "Enter radius for the second circle: ";
	cin >> r2;

	double radiusSumSq = (r1 + r2) * (r1 + r2);
	double distanceSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

	if (distanceSq == radiusSumSq)
	{
		cout << "The two circles touch each other.";
	}
	else if (distanceSq < radiusSumSq)
	{
		cout << "The two circles intersect each other.";
	}
	else
	{
		cout << "The two circles have no common points.";
	}

}