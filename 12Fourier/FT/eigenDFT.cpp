#include <cmath>
#include <complex>
#include "eigenDFT.h"
using namespace Eigen;
const int FORWARD = 1, INVERSE = -1;

// One Dimensional Constructor
// DFT, but not FFT
DFT::DFT(float *data,int Nn)
{
   N = Nn; 
   InitializeDFT();
   for(int i=0;i<N;i++)  x[i] = complex<float>(*(data+i),0.0);
}
DFT::DFT(int Nn)
{
   N = Nn;
   InitializeDFT();
}
DFT::~DFT(){ }
void DFT::InitializeDFT()
{
   x.resize(N);
   X.resize(N);
   F = new VectorXcf[N];
   IF = new VectorXcf[N];
   complex<float> j = complex<float>(0.0, 1.0);
   complex<float> W = j * complex<float>(2.0*3.141592/(float)N,0.0);
   complex<float> WW = W;
   W = exp(W);
   for (int n = 0; n < N; n++){
	   F[n].resize(N);
	   IF[n].resize(N);
	   F[n](0) = IF[n](0) = 1.0;
	   WW = pow(W, n);
	   for (int k = 1; k < N; k++) {
		   F[n](k) = F[n](k - 1)/WW;
		   IF[n](k) = IF[n](k - 1) * WW ;
	   }
	   for (int k = 0; k < N; k++) 
		   IF[n](k) /= complex<float>((float)N, 0.0);
   }
}
/**************************************
	 DFT algorithm
***************************************/
void DFT::ForwardDFT() { 
	for (int k = 0; k < N; k++) X(k) = x.dot(F[k]);
}
void DFT::InverseDFT() {
	for (int n = 0; n < N; n++) x(n) = X.dot(IF[n]);
}
