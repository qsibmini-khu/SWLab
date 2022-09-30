#pragma once
#include <complex>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

class DFT               
{
public:
	int N;            // N = 2**NU
	void InitializeDFT();
	VectorXcf *F,*IF;      

	DFT(int);               // one dimensional constructor
	DFT(float *,int);        // one dimensional constructor
	~DFT();

	void ForwardDFT();  // x[n] ==> X[k]
	void InverseDFT();  // X[k] ==> x[n]
	VectorXcf x,X;
};

