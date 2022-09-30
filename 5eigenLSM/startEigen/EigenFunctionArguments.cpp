#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
void npMatrix(const MatrixXd& data, MatrixXd& result) {
	result = data;
	result(1, 1) = -5;
}
void xpMatrix(MatrixXd* result) {
	(*result)(0, 0) = 15;
	(*result)(1, 1) = 15;
}
MatrixXd Matrixx2(const MatrixXd& data) {
	MatrixXd xx = 2.0 * data;
	return xx;
}
int main() {
	MatrixXd m(2, 2), n(2, 2);
	m << 3, 2.5, -1, 1.5;
	cout << " m\n" << m << endl;

	npMatrix(m, n);
	cout << " m\n" << m << endl;
	cout << " n\n" << n << endl;

	xpMatrix(&n);
	cout << " n\n" << n << endl;

	MatrixXd o = Matrixx2(m);
	cout << " o\n" << o << endl;
	return 2;
}