#include <iostream>
#include "matrix.h"
using namespace std;
matrix2d matrix2d::add(matrix2d a) {
	if (N != a.N || M != a.M) { cout << "  add: something wrong \n"; return a; 	}
	matrix2d b(N, M);
	int nm = N*M;
	for (int i = 0; i < nm; i++) b.mm[i] = a.mm[i] + mm[i];
	return b;
}
// matrix2d mult(matrix2d a) {};
void matrix2d::out() {
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) cout << mm[n * M + m] << "  ";
		cout << endl;
	}
}
void matrix2d::out(char* s) {
	cout << s << endl;
	out();
}
void matrix2d::copy(float* s) {
	int nm = N * M;
	for (int i = 0; i < nm; i++) mm[i] = s[i];
}
matrix2d matrix2d::mult(matrix2d a) {
	if (M != a.N) {
		cout << "something wrong" << endl;
	}
	matrix2d x(N, a.M);
	int K = a.N;
	int MM = a.M;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < MM; m++) {
			float sum = 0.;
			for (int k = 0; k < K; k++) {
				sum += mm[n * M + k] * a.mm[k * MM + m];
			}
			x.mm[n * MM + m] = sum;
		}
	}
	return x;
}