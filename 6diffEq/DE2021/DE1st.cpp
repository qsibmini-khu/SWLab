#include <fstream>
using namespace std;
const float f0 = 2.;
float analytic(float x) { return f0 * exp(-x / 5); }
float error(float nu, float an) { return (nu - an) / an * 100; }
int main() {
	float t = 0, dt = 0.1, T=10;
	float fn = f0, fn1;
	ofstream xx("de1st.txt");
	if (!xx) return 666;  // check if de1st.txt is open.
	for (t = 0; t < T; t += dt) {
		fn1 = fn * (1 - dt / 5);
		float an = analytic(t);
		xx << t << " " << fn << " " << an
			<< " " << error(fn, an) << endl;
		fn = fn1;
	}
	return 123;
}