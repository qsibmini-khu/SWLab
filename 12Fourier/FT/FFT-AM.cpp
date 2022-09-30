/***********************************
 test complex operation
 author : Doug Young Suh
 date   : 2020. 11.20

 FT of sin(2pi f t)cos(2pi fc t)
     signal frequency f = 440Hz   
	 carrier frequency fc = 2kHz
**************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include "Fft1D.h"
using namespace std;
const int N = 512;
const float pi = 3.141592;

// for modulation test
float xt(float t) {
	float f = 440;
	float fc = 2000;
	return sin(2. * pi * f * t) * cos(2. * pi * fc * t);
}
int main()
{
	long n,k;
	FFT *xx;
	xx = new FFT(N);
	float fs = 44100.0; // sampling frequency
	float dt = 1. / fs, df = fs/(double)N;

	for (n = 0; n < N; n++) {
		xx->x[n] = complex<double>(xt(n*dt), 0.0);
	}

	xx->ForwardFFT();

	ofstream fff("fft-AM.txt");
	for (k = N/2; k > 0; k--) {
		fff << -k * df << "  " << abs(xx->X[N-k]) << endl;
	}
	for (k = 0; k < N / 2; k++) {
		fff << k * df << "  " << abs(xx->X[k]) << endl;
	}
	fff.close();
	return 400;
}
