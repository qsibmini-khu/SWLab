//////////////////////////////////////////////////// 
//   Author: Doug Young Suh
//
//   LSM   y = ax + b
//
//   Date  : May. 2, 2020
////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/LU>
using namespace Eigen;
using namespace std;
int main() {
	Matrix2d A;
	Matrix2d IA;
	Vector2d B,C,D;
	/*/ test
	A(0, 0) = 1.; A(0, 1) = 2;
	A(1, 0) = 3.; A(1, 1) = 4;
	cout << A << endl;
	B[0] = 1; B[1] = 2;
	cout << " B " << B << endl;

	C = A * B;
	cout << C << endl;
	// Inverse test
	IA = A.inverse();
	D = IA * C;
	cout << "D " << D << endl;*/

	/// read data /////
	ifstream data1("data1.txt");
	int N;
	data1 >> N;
	float *x = new float[N];
	float *y = new float[N];
	for (int i=0; i < N; i++)
		data1 >> x[i] >> y[i];
	data1.close();  
	// make A and B
	//float minx = -1e100, maxx = 1e100;
	float Nx, Nxx, Ny, Nxy;
	Nx = Nxx = Ny = Nxy = 0.0;
	for (int i=0; i < N; i++) {
		Nx += x[i]; 
		Ny += y[i];
		Nxx += x[i] * x[i];
		Nxy += x[i] * y[i];
		//if (minx > x[i]) minx = x[i];
		//if (maxx < x[i]) maxx = x[i];
	}
	A(0, 0) = Nx; A(0, 1) = N; B[0] = Ny;
	A(1, 0) = Nxx; A(1, 1) = Nx; B[1] = Nxy;
	
	//  solve for a, b
	IA = A.inverse();
	C = IA * B;  // C = (a b)
	// output to show results
	ofstream xx("d1result.txt");
	for (int i=0; i < N; i++) {
		xx << x[i] << "  " << y[i] << "  "<< C[0] * x[i] + C[1] << endl;
	}
	xx.close();
	getchar();
}