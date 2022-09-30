#include <iostream>
#include "matrix.h"
using namespace std;
int main() {
	float b[] = { 0.5,0.5,0.5,0.5,
		 0.5,0.5,-0.5,-0.5,
		 0.5,-0.5,-0.5,0.5,
		 0.5,-0.5,0.5,-0.5
	};
	matrix2d A(4, 4), B(4, 4, b);
	A.copy(b);
	A.out((char*)" A ");
	B.out((char*)" B ");
	cout << " mult \n";
	matrix2d C = A.mult(B);
	C.out((char*)" C ");

	matrix2d D(4, 1);
	D.mm[0] = D.mm[1] = 100;
	D.mm[2] = D.mm[3] = 50;
	matrix2d E = A.mult(D);
	E.out((char*)" E ");
	return 123;
}