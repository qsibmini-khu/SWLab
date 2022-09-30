// Author : DougnYoung Suh
// Date on July 6, 2020
#include <iostream>
#include <fstream>
#include <cmath> // sin( )
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

int main() {
	// Sprint 1
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 999;
	waveHeader myHeader;
	xx.read((char*)&myHeader, sizeof(waveHeader));
	cout << "   sampleRate = " << myHeader.sampleRate << endl;
	xx.close();
	// Sprint 2
	short *data,leftdata,rightdata;
	int n = myHeader.sampleRate *5; // for 5 seconds
	data = new short[n * myHeader.numChannels];
	float dt = 1. / (float)(myHeader.sampleRate);
	float f1 = 261.63, f2 = 329.63, A = 10000.0;
	for (int i = 0; i < n; i++) {
		float t = i*dt;
		if (i == 44100 * 2) {
			f1 *= 2; f2 *= 2;
		}
		if (i == 44100 * 4) {
			f1 /= 2; f2 /= 2;
		}
		leftdata = (short)(A * cos(2.*3.141592*f1*t));
		rightdata = (short)(A * cos(2.*3.141592*f2*t));
		data[i * 2] = leftdata;
		data[i * 2+1] = rightdata;
	}
	ofstream mywave("mywave.wav", ios::binary | ios::out);
	mywave.write((char*)&myHeader, sizeof(waveHeader));
	mywave.write((char*)data, sizeof(short) * n * (myHeader.numChannels));
	mywave.close();
	getchar();

	return 1;
}