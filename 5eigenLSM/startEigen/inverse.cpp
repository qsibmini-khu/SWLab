#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
	// inverse 1
	Matrix3d m = Matrix3d::Random();
	cout << "Here is the matrix m:" << endl << m << endl;
	cout << "Its inverse is: " << endl << m.inverse() << endl;
	// inverse 2
	MatrixXd mm(4, 4);
	mm << 0.5, 0.5, 0.5, 0.5,
		0.5, 0.5, -0.5, -0.5,
		0.5, -0.5, -0.5, 0.5,
		0.5, -0.5, 0.5, -0.5;
	MatrixXd nn = mm.inverse();
	cout << "Here is the matrix mm:" << endl << mm << endl;
	cout << "Its inverse is: " << endl << nn << endl;
	cout << "M*n" << endl << mm * nn << endl;
	return 1;
}