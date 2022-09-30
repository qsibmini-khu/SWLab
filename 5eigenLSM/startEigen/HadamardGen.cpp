//   Author: Doug Young Suh
//   Date : Sep. 25, 2020
//
//    1. set  H1 
//    2. make H2
//    3. make H3
#include <iostream>
#include <fstream>
#include <iomanip>
#include <eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {	
	//    make H1
	Matrix2d H1(2, 2);
	H1 <<  1, 1, 1, -1;
	//    2. make H2
	MatrixXd H2(4, 4);
	H2.block<2, 2>(0, 0) = H1;
	H2.block<2, 2>(0, 2) = H1;
	H2.block<2, 2>(2, 0) = H1;
	H2.block<2, 2>(2, 2) = -H1;
	cout << "\n H2 \n" << H2 << endl;
	//    3. make H3
	MatrixXd H3(8, 8);
	H3.block<4, 4>(0, 0) = H2;
	H3.block<4, 4>(0, 4) = H2;
	H3.block<4, 4>(4, 0) = H2;
	H3.block<4, 4>(4, 4) = -H2;
	cout << "\n H2 \n" << H3 << endl;
	
	getchar();
	return 125;
}
