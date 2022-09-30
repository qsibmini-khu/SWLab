#pragma once
class linearFn {
public:
	linearFn() {
		N = 4;
		x = new float[N];
		y = new float[N];
		x[0] = 0.1; y[0] = 1.1;
		x[1] = -0.1; y[1] = 0.9;
		x[2] = 1.1; y[2] = 2.1;
		x[3] = 0.9; y[3] = 1.9;
	};
	linearFn(char *);
	int N;
	float *x, *y;
	float LossFn(float a, float b);
	float dfabda(float a, float b, float da);
	float dfabdb(float a, float b, float db); 
//private:
	float distance(float, float, float, float);
	//float EE(float, float, float, float);
};