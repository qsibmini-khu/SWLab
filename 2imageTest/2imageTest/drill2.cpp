#include <iostream>
#include "bmpNew.h"  // suh
int main() {
	int x, y;
	unsigned char* bmpB = ReadBmp("sunflower.bmp", &x, &y); // 24bits bmp
	if (!bmpB) {  // if "sunflower.bmp" is not found in this folder
		std::cout << "cannot find image file\n";
		return 666;
	}
	std::cout << " Main " << x << " by " << y << std::endl;
	int xy = x * y * 3;
	unsigned char* outbmp = new unsigned char[xy];
	// copy to *outbmp
	for (int i = 0; i < xy; i++) outbmp[i] = bmpB[i];
	// make red block
	for (int i = 0; i < 50; i++) {
		int ix = i * x * 3;
		for (int j = x - 100; j < x; j++) {
			outbmp[ix + j * 3] = 0;       // G
			outbmp[ix + j * 3 + 1] = 0;   // B
			outbmp[ix + j * 3 + 2] = 255; // R
		}
	}
	// write a bmp file
	WriteBmp("Red.bmp", outbmp, x, y);
	return 123;
}