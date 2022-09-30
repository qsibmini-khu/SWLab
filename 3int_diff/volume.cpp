//   Author : Doug Suh
//   Date :    July 7, 2020
//  1. area of square
//  2. area of triangle
//  3. area of circle
//  4. area of circle polar
#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.141592;
float error(float dd, float ss) { return fabs(dd - ss) / dd * 100; };
int main() {
	//  1. area of square
	float X = 100.0, Y = 50.0;
	float dx = X / 100.;
	float dy = Y / 100.;
	float area = 0;
	for (float x = 0; x < X; x += dx)
		for (float y = 0; y < Y; y += dy) area += dx * dy;
	cout << " rectangle " << X * Y  << "  " << area << endl;
	//  2. area of triangle
	area = 0;
	dx = X / 1000.;
	dy = Y / 1000.;
	for (float x = 0; x < X; x += dx){ 
		float ymax = -Y / X * x+Y;
		for (float y = 0; y < ymax; y += dy) area += dx * dy; 
	}
	cout << " triangle " << X * Y / 2. << "  " << area << "  " 
		 << error(X*Y/2.0,area) << "% error "<< endl;
	//  3. area of circle
	float R=100.0;
	area = 0;
	dx = X / 1000.;
	for (float x = -R; x < R; x += dx) {
		float ymax = sqrt(R*R-x*x);
		for (float y = -ymax; y < ymax; y += dy) area += dx * dy;
	}
	cout << " circle 1 " << pi*R*R << "  " << area << "  "
		<< error(3.141592 * R * R, area) << "% error " << endl;
	//  4. area of circle polarcircle
	R = 100.0;
	float th, dth;
	area = 0;
	dth = 2. * pi / 1000.;
	float dr = R / 1000.;
	for (float r = 0.; r < R; r += dx) {
		for (th = 0.0; th < 2. *pi; th += dth) area += r*dr * dth;
	}
	cout << " circle 2 " << pi * R * R << "  " << area << "  "
		<< error(pi * R * R, area) << "% error " << endl;
	return 1;
}