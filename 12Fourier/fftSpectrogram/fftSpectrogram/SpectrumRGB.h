#pragma once
class SpectroRGB {
public:
	SpectroRGB() {
		// blue --> green
		for (int i = 0; i < 60; i++) {
			R[i] = 0;
			B[i] = 255 - (unsigned char)(255 * i / 60);
			G[i] = (unsigned char)(255 * i / 60);
		}
		// green --> yellow
		for (int i = 60; i < 120; i++) {
			B[i] = 0;
			G[i] = 255;
			R[i] = (unsigned char)(255 * (i-60) / 60);
		}
		// yellow --> red
		for (int i = 120; i < 180; i++) {
			B[i] = 0;
			G[i] = 255-(unsigned char)(255 * (i - 120) / 60);
			R[i] = 255;
		}
		// red --> dark red
		for (int i = 180; i < 256; i++) {
			B[i] = 0;
			G[i] = 0;
			R[i] = 255-(unsigned char)(255 * (i - 180) / 120);
		}
	};
	unsigned char R[256], G[256], B[256];
};
