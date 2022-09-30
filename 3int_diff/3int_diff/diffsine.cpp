#include <fstream>
const float PI = 3.141592;
using namespace std;
float f1(float);  // original function
float f2(float);  // analytic solution
float f3(float,float); // numerical solution
int main() {
	ofstream myout("diff.txt");
	float dt = 0.001, t = 0.0;
	for (int i = 0; i < 50; i++) {
		myout << t << " " << f2(t) << " " << f3(t, dt) << "\n";
		t += dt;
	}
	myout.close();
	return 1;
}
float f1(float t){ return sin(2 * PI * 220 * t); }
float f2(float t){ return 440. * PI * cos(2 * PI * 220 * t); }
float f3(float t, float dt) { 
	float dt2 = dt / 2;
	return (f1(t + dt2) - f1(t-dt2)) / dt;  
}   // better than (f1(t+dt)-f1(t))/dt Why?