#include <fstream>
using namespace std;
const float f0 = 2.;
int main() {
	float t = 0, dt = 0.1, T = 10;
	float fn = f0, fn1;
	ofstream xx("deNon.txt");
	if (!xx) return 666;  // check if de1st.txt is open.
	for (t = 0; t < T; t += dt) {
		float et = exp(-(t + dt / 2) * (t + dt / 2))/2;
		fn1 = fn * (1/dt - et) / (1 / dt + et);
		xx << t << " " << fn << endl;
		fn = fn1;
	}
	return 123;
}