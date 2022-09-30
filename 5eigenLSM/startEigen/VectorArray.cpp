#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
	VectorXd* xX = new VectorXd[10];
	for (int i = 0; i < 10; i++) {
		xX[i] = VectorXd(4);
		for (int j = 0; j < 4; j++) xX[i][j] = i + j;
		cout << "\n\n" << xX[i] << endl;
	}
	// orthogonal
	xX[0] << 0.5, 0.5, 0.5, 0.5;
	xX[1] << 0.5, 0.5, -0.5, -0.5;
	xX[2] << 0.5, -0.5, -0.5, 0.5;
	xX[3] << 0.5, -0.5, 0.5, -0.5;
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) { cout << xX[i].dot(xX[j]) << " "; 	}
		cout << endl;
	}

	return 1;
}