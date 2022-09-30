#include <iostream>
const float g = 9.8;
using namespace std;

void calculate_x(float);
int main() {
	float ddt = 0.125; // 2^n where n = -3
	for (int i = 0; i < 5; i++) {
		calculate_x(ddt);
		ddt *= 0.125;  // 2^n where n = -3, -6, -9, -12, -15
	}
	return 1;
}
// [0,10) integration of v(t) = gt for the time step dt
void calculate_x(float dt) {
	float t, T = 10, v, xbar, errorinpercent;
	xbar = 0;
	for (t = 0; t < T; t += dt) {
		xbar += g * (t + dt / 2) * dt;
		//xbar += g * t * dt; 
	}
	errorinpercent = fabs(490.0 - xbar) / 490.0 * 100.0;
	cout << "dt " << dt << " x=490 " << xbar << " error " << errorinpercent << "%\n";
};

/*int main() {
	float t, T = 10, v, xbar, errorinpercent;
	float dt = 0.01; xbar = 0;
	for (t = 0; t < T; t += dt) {
		xbar += g * (t + dt / 2) * dt;  // better than g*t*dt. Why??
	}
	errorinpercent = fabs(490.0 - xbar) / 490.0 * 100.0;
	cout << "dt " << dt << " x=490 " << xbar << " error " << errorinpercent << "%\n";
	return 1;
}*/