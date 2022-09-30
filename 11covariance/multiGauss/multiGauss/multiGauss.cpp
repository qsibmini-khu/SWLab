//   Author : Doug Young Suh
//   Date : July 10, 2020
//
//   titled 2D Gaussian dist
//   out: txt file of 3 tilted groups
//
//   1. generate (x, y) 
//   2. affine transform for (x' y')
//   3. write on txt file
//   4. next group
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
const float pi = 3.141592;
void affineXform(float xp, float yp, float *Ai, float *x, float *y) {
	*x = xp*Ai[0] + yp * Ai[1];
	*y = xp*Ai[2] + yp * Ai[3];
}
float Gaussian(float x) { 
	float mu = 0.0,sigma = 1.0;
	return exp(-(x-mu) * (x-mu)/2.0/sigma/sigma)/sigma/sqrt(2.0*pi); 
}

int main() {
	// data set in class 1
	float x, y, xp, yp;
	float A[4] = { 0.8, -0.8, 0.4, 0.4};
	ofstream xxx("tiltx.txt");
	xxx << "     00    ";
	for (int j = -10; j < 11; j++) {
		xxx << setw(10) << j << "  ";
	}
	xxx << endl;
	for (int i = -10; i < 11; i++) {
		xxx << setw(10) << i << "  ";
		yp = (float)i;
		for (int j = -10; j < 11; j++) {
			xp = (float)j;
			affineXform(xp, yp, A, &x, &y);
			xxx << setw(10) << Gaussian(x)*Gaussian(y) << "  ";
		}
		xxx << endl;
	}
	xxx.close();

	return 123;
}