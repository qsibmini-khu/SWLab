// DougFo Sep. 29, 2022  pdf of dice
#include <iostream>
using namespace std;
int main() {
	int hits[6], Ntry = 10000;
	cout << " RAND_MAX = " << RAND_MAX << endl;
	for (int i = 0; i < 6; i++) { hits[i] = 0; }
	for (int n = 0; n < Ntry; n++) {
		hits[rand() % 6]++;
	}
	for (int i = 0; i < 6; i++) 
	 cout << i+1 << " " << (float)hits[i] / Ntry << endl;
	return 123;
}