//   DFT with Eigen library
//
//  Author : Doug Young Suh
//  Date :   Nov. 19, 2020
//
///////////////////////////////
#include <iostream>
#include <fstream>
#include <complex>
#include <Eigen/Dense>
#include "eigenDFT.h"
using namespace std;
using namespace Eigen;
const int N = 32;
int main() {
	DFT mydft(N);
	// square signal
	for (int n = 0; n < N; n++) {
		mydft.x[n] = complex<float>(0.0, 0.0);
		if(n<4 || n>N-4)mydft.x[n] = complex<float>(1.0, 0.0);
	}
	// show orthogonality
	cout << " 1 1 " << mydft.F[1].dot(mydft.F[1]) << endl;
	cout << " 5 1 " << mydft.F[5].dot(mydft.F[1]) << endl;
	cout << " 7 9 " << mydft.F[7].dot(mydft.F[9]) << endl;
	mydft.ForwardDFT();
	// sinc function
	for (int k = 0; k < N; k++) cout << abs(mydft.X(k)) << endl;
	cout << "   \n\n";
	mydft.InverseDFT();
	cout << "   \n IF\n";
	cout << mydft.IF[4] << endl;
	cout << "   \n  x\n";
	for (int n = 0; n < N; n++) cout << abs(mydft.x(n)) << endl;
	return 123;
}