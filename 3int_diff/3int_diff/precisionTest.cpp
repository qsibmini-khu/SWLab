#include <iostream>
using namespace std;
int main() {
	float x1 = 0.1, y1 = 0.125;
	double x2 = 0.1, y2 = 0.125;
	double dx1x2 = x2 - x1;
	double dy1y2 = y2 - y1;
	cout << dx1x2 << " " << dy1y2 << endl;
	int* z1 = (int*)&y1;
	cout << y1 << " " << hex << *z1 << endl;
	y1 /= 2.0;
	cout << y1 << " " << hex << *z1 << endl;
	return 123;
}