#include <fstream> // for FILE 
#include <iostream> 
using namespace std;
#include "GDlinearFn.h"

linearFn::linearFn(char *xx) {
	ifstream dataFile(xx);
	if (!dataFile)	exit(666);
	dataFile >> N;
	//N = 4;// debug
	x = new float[N];
	y = new float[N];
	for (int i = 0; i < N; i++) dataFile >> x[i] >> y[i];
	for (int i = 0; i < N; i++)
		cout << " data " << x[i] << " " << y[i] << endl;
}
// distance between (x,y) and projection point
// modified Sep. 20, 2020 : the distance equation
float linearFn::distance(float a, float b, float xx, float yy) {
	float p;
	p = (a * xx - yy + b) * (a * xx - yy + b) /(1+a*a);
	return p;
}
float linearFn::LossFn(float a, float b) {
	float sum = 0.0;
	for (int i = 0; i < N; i++) {
		sum += distance(a,b, x[i],y[i]);
	}
	return sum;
}
float linearFn::dfabda(float a, float b, float da) { 
	cout << "dfabda "<< LossFn(a + da, b) << endl;
	cout << "dfabda " << LossFn(a, b) << endl;
	return (LossFn(a+da,b) - LossFn(a,b)) / da; 
}
float linearFn::dfabdb(float a, float b, float db) {
	cout << "dfabdb " << LossFn(a, b+db) << endl;
	cout << "dfabdb " << LossFn(a, b) << endl;
	return (LossFn(a, b+db) - LossFn(a, b)) / db;
}
//float linearFn::EE(float, float, float, float) { ; }