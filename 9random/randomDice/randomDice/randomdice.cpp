// Written by Doug Young Suh on Dec. 26, 2020 copy-left
#include "randomdice.h"
void discreteRV::init(int nn, int ll, int hh) {
	N = nn;
	xlow = ll;
	xhigh = hh;
	pdf = new float[N];
	EX = VAR = 0;
	for (int i = 0; i < N; i++) pdf[i] = 0.0;
}
// calculate EX and VAR from pdf
void discreteRV::calculateExVar() {
	float EX2 = 0.0;
	EX = 0.0;
	for (int i = 0; i < N; i++) {
		EX += pdf[i] * (xlow + i);
		EX2 += pdf[i] * (xlow + i) * (xlow + i);
	}
	VAR = (EX2 - EX * EX);
}
// calculate pdf, EX, and VAR experimentally
void dice::experiment() {
	for (int i = 0; i < Ntry; i++) {
		int ix = rand() % 6;
		float x = ix + 1;
		EX += x;
		VAR += x * x;
		pdf[ix]++;
	}
	EX /= Ntry;
	VAR = VAR / Ntry - EX * EX;
	for (int i = 0; i < N; i++) {
		pdf[i] /= Ntry;
	}
}
