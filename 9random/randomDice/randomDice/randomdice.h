// Written by Doug Young Suh on Dec. 26, 2020 copy-left
#pragma once
#include <iostream>
#include <cmath>
using namespace std;
const int Ntry = 10000;
class discreteRV {
public:
	discreteRV() {}
	discreteRV(int nn, int ll, int hh) {
		init(nn, ll, hh);
	}
	void init(int nn, int ll, int hh); 
	int N; // number of elements
	int xlow, xhigh; // lowest and highest elements
	float* pdf;
	float EX, VAR;
	void calculateExVar(); 
	virtual void experiment() { };
};
class dice : public discreteRV {
public:
	dice() {};
	dice(int nn, int ll, int hh) {
		init(nn, ll, hh);
		experiment();
	}
	void experiment(); 
};