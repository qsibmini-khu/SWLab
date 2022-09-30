/***********************************
 test fft operation
 author : Doug Young Suh
 date   : 99.9.17

  Revision 1: 2000.8.25 Doug Young Suh 
   include fft test.
  Revision 2: 2013. 1. 8 
   Read an image and fft line by line
  Revision 3: 2014. 4. 30  ==> delete
   add two more test
   (square) <--> (sinc)
   (sinc)   <--> (square)
  Revision 4: 2014. 5. 11
   only 1 dimensional FFT  (Fft1D.hpp Fft1D.cpp)
  Revision 5: 2020. 6. 8
   complex class
***************************************/
#include <iostream>
#include <fstream>
#include <complex>
#include "fft1D.h"
int main()
{
	long n,k;
	/////////////////////////////////////////
	FFT *sequence;
	sequence = new FFT(512);
	int N = 512;

	// test 1: DFT of square x[n]
	for(n=0;n<N;n++)    sequence->x[n] = complex<double>(0.0,0.0);
	for(n=0;n<16;n++)   sequence->x[n] = complex<double>(1.0,0.0);
	for(n=N-15;n<N;n++) sequence->x[n] = complex<double>(1.0,0.0);
	sequence->ForwardFFT();
	ofstream fff("DFTofSquare.txt");
	if(!fff) {
		cout << "cant open DFTofSquare.txt.\n";
		return 333;
	}
	for(k=N/2;k<N-1;k++) fff << sequence->X[k].real() << endl;
	for(k=0;k<N/2+1;k++) fff << sequence->X[k].real() << endl;
    fff.close();

	// test 2: DFT of ideal low pass filter X[k]
	for(k=0;k<N;k++)    sequence->X[k] = complex<double>(0.0,0.0);
	for(k=0;k<16;k++)   sequence->X[k] = complex<double>(1.0,0.0);
	for(k=N-15;k<N;k++) sequence->X[k] = complex<double>(1.0,0.0);
	sequence->InverseFFT();
	ofstream ggg("IDFTofLPF.txt");
	if (!ggg) {
		cout << "cant open IDFTofLPF.txt.\n";
		return 334;
	}
	for (n = N / 2; n<N - 1; n++) ggg << sequence->x[n].real() << endl;
	for (n = 0; n<N / 2 + 1; n++) ggg << sequence->x[n].real() << endl;
	ggg.close();

	return 400;
}

