//  bmpNew.h SpectrumRGB.h
//
//  Test pseudo color
//
//  Author : Doug Young Suh
//  Date : Nov. 27, 2020
//
#include <iostream>
#include <fstream>
//#include <complex> 
//#include "fft1d.h"
#include "SpectrumRGB.h"
#include "bmpNew.h"
using namespace std;
int main() {
	SpectroRGB myrgb;
	/* peuso color OK
	for (int i = 0; i < 256; i++) {
		cout <<(int)myrgb.R[i] << " " << (int)myrgb.G[i] << " " << (int)myrgb.B[i] << " \n";
	}*/
	// image test
	unsigned char im[100 * 256 * 3];
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 100; j++) {
			unsigned char* now = im + (i * 100 + j) * 3;
			now[0] = myrgb.B[i];
			now[1] = myrgb.G[i];
			now[2] = myrgb.R[i];
		}
	}
	if(WriteBmp("pallete.bmp", im,100, 256)) cout << " true\n"; // OK
	return 123;
}