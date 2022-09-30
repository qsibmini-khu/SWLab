/***************************************************************************
* DESCRIPTION:
* Wave equation in cylindrical coordinate
* 
*
* AUTHOR: Doug Young Suh
* LAST REVISED:  July 8, 2020
***************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "DiffEqAntenna.h"
using namespace std;

int main() {
	float data[200 * 20];
	antenna s1(1e6,200);
	for (int i = 0; i < 20; i++) {
		s1.update();
		for (int j = 0; j < 200; j++) data[i * 200 + j] = s1.R[j];
	}
	ofstream xx("DEAntenna.txt");
	xx << "               ";
	for (int i = 0; i < 20; i++) xx << setw(15) << i * s1.dt << " "; xx << "\n";
	for (int j = 0; j < 200; j++) {
		xx << setw(15) << s1.dr * j << " ";
		for (int i = 0; i < 20; i++) xx << setw(15) << data[i*200+j] << " "; xx << "\n";
	}
	xx.close();
	return 1;
}

