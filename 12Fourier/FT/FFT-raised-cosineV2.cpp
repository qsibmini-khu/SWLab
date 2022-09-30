/***********************************
 test complex operation
 author : Doug Young Suh
 date   : 2016. 11.29

 No = 25크기의 raised cosine와 square window의 FT를 구한다. .
 Revision: Nov. 18, 2020
   - fft2020 version으로 수정
**************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <Windows.h>
#include "Fft1D.h"
using namespace std;
const int N = 1024;
const float PH = 3.141592;

float xt(float);

int main()
{
	long n,k;
	unsigned int starttime, endtime;
	starttime = GetTickCount();
	/////////////////////////////////////////
	FFT *xx1,*xx2;
	xx1 = new FFT(N);
	xx2 = new FFT(N);

	for (n = 0; n < N; n++)		xx1->x[n] = xx2->x[n] = complex<double>(0.0, 0.0);
	for (n = 1; n < 13; n++) {
		xx1->x[n] = xx1->x[N - n] = complex<double>(1.0, 0.0);
		xx2->x[n] = xx2->x[N - n] = complex<double>((cos(2. * 3.141592 * n / 24.) + 1.0) / 2.0, 0.0);
	}
	
	/*// modulation test quiz 3
	float dt = 1. / 6.e5;
	float t = 0.0;
	xx1->x[0] = complex<double>(xt(0.0), 0.0);
	xx1->x[N/2] = complex<double>(0.0, 0.0);
	for (n = 1; n < N/2; n++) {
		t += dt;
		xx1->x[n] = xx1->x[N - n] = complex<double>(xt(t), 0.0);
	}*/

	xx1->ForwardFFT();
	xx2->ForwardFFT();

	ofstream fff("raised-cosine2.txt");
	for (k = 0; k < N; k++){
		fff << k << "  " << xx1->X[k].real() << "  " << xx2->X[k].real() << endl;
	}
	fff.close();

	//endtime = GetTickCount() - starttime;
	//printf(" %d\n", endtime);
	return 400;
}
// for modulation test
float xt(float t) {
	float xtt;
	if (t == 0.0) t = 1.0e-10;
	xtt = sin(2 * PH*16.0e3*t) / PH / t*cos(2 * PH*1.0e5*t);
	//xtt += (sin(2 * PH*16.0e3*t) / PH / t) * (sin(2 * PH*16.0e3*t) / PH / t) * cos(2 * PH*2.0e5*t) / 0.3e5;
	xtt -= (sin(2 * PH*16.0e3*t) / PH / t) * cos(2 * PH*2.0e5*t);
	return xtt;
}