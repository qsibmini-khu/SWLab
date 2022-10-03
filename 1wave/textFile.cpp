#include <iostream>
#include <fstream>
using namespace std;
int main() {
	/// write a text file
	ofstream hong("gil.txt");
	if (!hong) return 666; // if not open the file, quit
	float x, y, z;
	x = 3.14;
	y = 2.72;
	z = 174.;
	hong << "pi " << x << endl;
	hong << "expo " << y << endl;
	hong << "height " << z << endl;
	hong.close(); // store as a file in the hard-disk

	/// read the file
	ifstream dong("gil.txt");
	if (!dong) return 777; // if not open the file, quit
	char name[20];
	float a, b, c;
	dong >> name >> a;
	cout << name << " " << a << endl;
	dong >> name >> b;
	cout << name << " " << a << endl;
	dong >> name >> c;
	cout << name << " " << c << endl;
	return 123;
}