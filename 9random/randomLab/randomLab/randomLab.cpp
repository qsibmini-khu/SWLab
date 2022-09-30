// Author: Doug Young Suh
// Date:   July 15, 2020
//
//      Tetris (Monte Carlo)
//      pi
//      seed srand( )
//
// Compare experiment and theory: binomial dist.
//      n = 10, p = 1/6       N=10000 trials
//      P[0~n], E[X] and V[X]
//
//  Gaussian dist library
//      E[X] and V[X]    N=10000 trials
//////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <random>
using namespace std;
///////////////  Binomial //////////////
/*const int n = 10, N = 10000;
const float p = 1.0 / 6.0; // dice
// prob of x for binomial dist (n, p)
float fac(float x) { if (x == 0.0 || x == 1.0) return 1.0; 
return x * fac(x - 1); }
float calc_px(float p, int x, int n) {
	return pow(p,x)*pow((1.0-p),(n-x))*fac(n)/fac(x)/fac(n-x);
};*/
const int N = 200;

int main() {


	////   Tetris //////////////////////////
	/*float p[] = { 12.3, 26.5, 17.23,22.3, 9.2,12.47 };
	float P[6], PP[6];
	P[0] = p[0];   PP[0] = 0;
	for (int i = 1; i < 6; i++) {
		P[i] = P[i-1]+p[i];  PP[i] = 0;
	}
	for (int i = 0; i < 10000; i++) {
		float rr = rand() / (float)RAND_MAX *100.0;
		if (rr < P[0]) PP[0] += 1.0;
		else if (rr < P[1]) PP[1] += 1.0;
		else if (rr < P[2]) PP[2] += 1.0;
		else if (rr < P[3]) PP[3] += 1.0;
		else if (rr < P[4]) PP[4] += 1.0;
		else  PP[5] += 1.0;
	}
	for (int i = 0; i < 6; i++){
		PP[i] /= (float)100;
		cout << "  " << i << "  " << PP[i] << "  " << p[i]<<"\n";
    }*/

	////    pi    //////////////////////////
	/*float x, y,hit = 0;
	for (int i = 0; i < 10000; i++) {
		x = (rand() / (float)RAND_MAX - 0.5) * 2;
		y = (rand() / (float)RAND_MAX - 0.5) * 2;
		if (x*x + y * y < 1.0) hit += 1.0;
	}
	cout << hit / (float)10000 * 4.0 << "\n";*/
	////    seed srand() ///////////////////
	srand(100);
	for (int i = 0; i < 10; i++) cout << rand() << " "; cout << "\n";
	srand(200);
	for (int i = 0; i < 10; i++) cout << rand() << " "; cout << "\n";
	srand(100);
	for (int i = 0; i < 10; i++) cout << rand() << " "; cout << "\n";
	srand(200);
	for (int i = 0; i < 10; i++) cout << rand() << " "; cout << "\n";
	///////////////  Binomial //////////////
/*	// variables: PX[n+1]  mean  var
	float PX[n + 1], mean = 0.0, var = 0.0;
	for(int x=0;x<=n;x++)PX[x]=0.0;
	// N experiments
	for (int i = 0; i < N; i++) {
		int n6 = 0;
		for (int j = 0; j < n; j++) {
			if ((float)rand() / (float)RAND_MAX < p) n6++;
		}
		PX[n6] += 1.0;
		mean += n6;
		var += n6 * n6;
	}
	// experiment result
	for (int x = 0; x <= n; x++) PX[x] /= (float)N;
	mean /= (float)N; // E(X)
	var /= (float)N;  // E(X^2)
	var -= mean * mean; // E(x^2) - E(X)^2
	// theoretical: PX[n+1]  mean  var 
	ofstream xx("bino.txt");
	xx << "  mean " << mean << "  " << n * p << "\n";
	xx << "  Var  " << var  << "  " << n * p *(1-p) << "\n\n prob. \n";
	for (int x = 0; x < n + 1; x++) {
		xx << "  " << x << " " << PX[x] << "  " << calc_px(p, x, n) << "\n";
	}
	xx.close();*/
	///////////////  Gaussian  /////////////
	/*default_random_engine generator;
	normal_distribution<double> myGauss(5.0, 2.0);
	double EX=0, Var=0;
	int N = 10000;
	for (int i = 0; i < N; i++) {
		double number = myGauss(generator);
		EX += number;
		Var += number * number;
	}
	EX /= (double)N;
	Var /= (double)N;
	Var = Var - EX * EX;
	cout << " mean " << EX << "  " << "5.0\n";
	cout << " Var " << Var << "  " << "4.0\n";*/
	getchar();
	return 123;
}
