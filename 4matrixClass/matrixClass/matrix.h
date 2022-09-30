#pragma once
class matrix2d {
public:
	matrix2d() { allocate(2,2);	}
	matrix2d(int n, int m) { allocate(n, m); }
	matrix2d(int n, int m, float *a) {
		allocate(n, m);
		copy(a);
	}
	void allocate(int n, int m) {
		N = n; M = m;
		mm = new float[N * M];
	}
	int N, M;
	float* mm;
	matrix2d add(matrix2d);
	matrix2d mult(matrix2d);
	void out();
	void out(char*);
	void copy(float*);
};