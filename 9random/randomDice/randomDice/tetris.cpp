// DougFo Sep. 29, 2022  Monte Carlo for tetris
#include <iostream>
using namespace std;
int main() {      // a    b    c    d    e   f
	float pdf[] = {12.3,26.5,17.23,22.3,9.2,12.47 }, cdf[6], x;
	cdf[0] = pdf[0];
	int i, hits[6], Ntry = 10000;
	for (i = 1; i < 6; i++)  cdf[i] = cdf[i-1]+pdf[i]; 
	for (i = 0; i < 6; i++) { hits[i] = 0; }
	for (int n = 0; n < Ntry; n++) {
		x = (float)rand() / RAND_MAX * 100.0;
		for (i = 0; i < 6; i++) if (x < cdf[i]) break;
		hits[i]++;
	}
	for (i = 0; i < 6; i++)
		std::cout << i + 1 << " " << (float)hits[i] / Ntry *100.0 << endl;
	return 123;
}