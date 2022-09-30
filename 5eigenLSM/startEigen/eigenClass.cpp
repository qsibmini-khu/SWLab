#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
class eclass {
public:
	eclass() {};
	eclass(int N, int M) {
		v.resize(M); // M by 1
		m.resize(N,M); // N by M
	};
	VectorXd v, w1, w2;
	MatrixXd m;
	VectorXd mv() {
		w1 = m * v;
		return w1;
		// return v*m; // error!!
	}
};
int main() {
	eclass mm(3, 2);
	mm.m << 3, 2, -1, 4, 1, -2;
	cout << " m\n" << mm.m << endl;
	mm.v << 3, 2;
	cout << " v\n" << mm.v << endl;

	mm.w2 = mm.mv();

	cout << " m*v = w\n" << mm.w1 << endl;
	cout << " m*v = w\n" << mm.w2 << endl;

	return 123;
}