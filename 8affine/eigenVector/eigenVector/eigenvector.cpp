// Author : Doug Young SUh
// Date :   July 10, 2020
//
//   Calculate eigenvalues and eigenvecgors of 3X3 matrix
//   Show decomposition A = P*S*PI
//////////////////////////////////////////////////////////
#include <iostream>
#include <eigen/Dense>
#include <eigen/LU>
using namespace Eigen;
using namespace std;

int main()
{
	MatrixXd A  (3,3);
	A << 2,0,-2,
		1, 1, -2,
		0, 0,1;

	EigenSolver<MatrixXd> es;
	es.compute(A);
	cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
	MatrixXd P(3, 3);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) 
		P(i, j) = es.eigenvectors()(i, j).real();
	cout << "\n\nP\n" << P << endl;

	MatrixXd S(3, 3);
	//S.Zero();
	for (int i = 0; i < 3; i++) S(i,i) = es.eigenvalues()[i].real();
	MatrixXd PI = P.inverse();

	cout <<"\n\nA=PSPi\n"<< P * S * PI << endl;

	getchar();
}