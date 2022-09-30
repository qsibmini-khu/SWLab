// Author : DougnYoung Suh
// Date on Nov. 27, 2020
//
// Make a bmp file for the spectrogram of Beatles.wav
// 
#include <iostream>
#include <fstream>
#include <complex> 
#include "fft1d.h"
//#include "SpectrumRGB.h"
//#include "bmpNew.h"
using namespace std;

class waveHeader {
public:
	waveHeader() {};
	int chunkID, chunkSize, Format, subChunkID, subChunk1size;
	short	audioFormat, numChannels;
	int sampleRate, byteRate;
	short blockAlign, bitsPerSample;
	int subChunk2ID, subChunk2size;
};

const int N = 2048;
const int Nfft = 610; // 5MB / 2048 sample/fft / 4byte/sample
int main() {
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 999;
	waveHeader myHeader;
	xx.read((char*)&myHeader, sizeof(waveHeader));

	// FFT
	FFT spectrum(N);
	float fXk[N * Nfft / 2],max=0.0; // store abs(X[k]) for k=0~N/2-1 
	short xnreal[2*N];

	for (int nfft = 0; nfft < Nfft; nfft++) {
		xx.read((char*)xnreal, 2 * N * sizeof(short));
		for(int n=0;n<N;n++){
			spectrum.x[n] = complex<float>((float)xnreal[n * 2], 0.0);
		}
		spectrum.ForwardFFT();
		for (int k = 0; k < N/2; k++) {
			float absXk = abs(spectrum.X[k]);
			fXk[nfft * N / 2 + k] = absXk;
			if (max < absXk) max = absXk;
		}
	}
	xx.close();

	cout << " max |Xk| " << max << endl;
/*	// image
	unsigned char* image = new unsigned char[Nfft * N / 2 * 3];
	SpectroRGB RGBtable;
	for (int nfft = 0; nfft < Nfft; nfft++) {
		for (int k = 0; k < N / 2; k++) {
			unsigned char* now = image + k * Nfft * 3 + nfft * 3;
			unsigned char level = (unsigned char)(fXk[nfft * N / 2 + k] / max * 254);
			*now = RGBtable.B[level]; 
			*(now+1) = RGBtable.G[level]; 
			*(now+2) = RGBtable.R[level];
		}
	}
	WriteBmp("BeatlesSpectrogram.bmp",image, Nfft, N / 2);*/
	getchar();
	return 1;
}