// Author : DougnYoung Suh
// Date on Nov. 27, 2020
//
// Make a bmp file for the spectrogram of Beatles.wav
// 
#include <iostream>
#include <fstream>
#include <complex> 
#include "fft1d.h"
#include "SpectrumRGB.h"
#include "waveheader.h"
#include "bmpNew.h"
using namespace std;

const int N = 2048, Nfft = 600; // 5MB / 2048 sample/fft / 4byte/sample
const int scale = 8; // up to 10kHz
int main() {
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 999;
	waveHeader myHeader;
	xx.read((char*)&myHeader, sizeof(waveHeader));
	cout << myHeader.sampleRate << endl;

	// FFT
	FFT spectrum(N);
	float* fXk, max = 0.0; // store abs(X[k]) for k=0~N/2-1 
	short xnreal[2 * N];
	fXk = new float[N * Nfft / 2];

	for (int nfft = 0; nfft < Nfft; nfft++) {
		xx.read((char*)xnreal, 2 * N * sizeof(short));
		for (int n = 0; n < N; n++) {
			spectrum.x[n] = complex<float>((float)xnreal[n * 2], 0.0);
		}
		spectrum.ForwardFFT();
		for (int k = 0; k < N / scale; k++) {
			float absXk = abs(spectrum.X[k]);
			/* in dB
			if (absXk < 1.0) absXk = 1.00001;
			absXk = 20 * log10(absXk);*/
			fXk[nfft * N / 2 + k] = absXk;
			if (max < absXk) max = absXk;
		}
	}
	xx.close();

	cout << " max |Xk| " << max << endl;

	// image
	unsigned char* image = new unsigned char[Nfft * N / scale * 3];
	SpectroRGB RGBtable;
	for (int nfft = 0; nfft < Nfft; nfft++) {
		for (int k = 0; k < N / scale; k++) {
			unsigned char* now = image + k * Nfft * 3 + nfft * 3;
			float imxx = fXk[nfft * N / 2 + k] / max * 2048; // peak is too high. Let the max as peak/8;
			if (imxx > 256) imxx = 255;
			unsigned char level = (unsigned char)imxx;
			*now = RGBtable.B[level];
			*(now + 1) = RGBtable.G[level];
			*(now + 2) = RGBtable.R[level];
		}
	}
	WriteBmp("BeatlesSpectrogram.bmp", image, Nfft, N / scale);
	return 123;
}