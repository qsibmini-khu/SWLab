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
#include <random>
using namespace std;
const int N = 200;
//  vec(x) = A vec(x')
void affineXform(int xp, int yp, float *Ai, int *x, int *y) {
	*x = (int)(xp*Ai[0] + yp * Ai[1]);
	*y = (int)(xp*Ai[2] + yp * Ai[3]);
}
int main() {
	default_random_engine generator;
	normal_distribution<double> g1(-200, 150);
	normal_distribution<double> g2(200, 50);

	// data set in class 1
	int x, y, xp, yp;
	float A[4] = { 1, 1, -1, 1 };
	ofstream xxx("tilt.txt");
	for (int i = 0; i < N; i++) {
		xp = (int)g1(generator);
		yp = (int)g2(generator);
		affineXform(xp, yp, A, &x, &y);
		xxx << x << "   " << y << "\n";
	}

	for (int i = 0; i < N; i++) {
		xp = (int)g1(generator) ;
		yp = (int)g2(generator) + 650;
		affineXform(xp, yp, A, &x, &y);
		xxx << x << "   " << y << "\n";
	}

	for (int i = 0; i < N; i++) {
		xp = (int)g1(generator) ;
		yp = (int)g2(generator) - 550;
		affineXform(xp, yp, A, &x, &y);
		xxx << x << "   " << y << "\n";
	}
	xxx.close();

	return 1;
}