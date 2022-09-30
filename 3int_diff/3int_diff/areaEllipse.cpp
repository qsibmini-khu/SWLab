#include <iostream>
using namespace std;
const float PI = 3.141592;
float ellipseArea(float, float);
int main() {
	cout << ellipseArea(3, 4) << " " << PI*3*4 << endl;
}
float ellipseArea(float a, float b) {
	float area = 0.0,PI2 = 2*PI,dth=PI/100,dr=b/50;
	for (float th = 0; th < PI2; th += dth) {
		float R = sqrt(a * cos(th) * a * cos(th) + b * sin(th) * b * sin(th));
		for (float r = 0; r < R; r += dr) area += r * dr * dth;
	}
	return area;
}