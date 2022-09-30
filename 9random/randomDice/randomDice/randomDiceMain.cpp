// Written by Doug Young Suh on Dec. 26, 2020 copy-left
#include <iostream>
#include <cmath>
using namespace std;
#include "randomdice.h"
int main() {
	// dice rolling
	dice mydice(6, 1, 6);
	mydice.experiment();
	cout << "  dice EX " << mydice.EX << endl;
	cout << "  dice VAR " << mydice.VAR << endl;
	cout << " P[x]  " << mydice.pdf[0] << endl;
	mydice.calculateExVar();
	cout << "  dice EX " << mydice.EX << endl;
	cout << "  dice VAR " << mydice.VAR << endl;
	return 123;
}