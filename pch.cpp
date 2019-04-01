// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"
#include <cmath>
#include "math.h"
#include <iostream>
using namespace std;

#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862

double calculateArea(double n) {
	if ( n<0 || n>0.5) return 0;
	//double n1 = 1 / PI;
	double n2 = acos(1 - 2 * n);
	double n3 = 2 * (1 - 2 * n)*sqrt(n - n * n);

	//cout << "acos = " << n2 << " n3 = " << n3 << endl;
	return n2 - n3;
}

bool shouldBeLargerOrNot(double i, const double area) {
	if (calculateArea(i) < area) {
		return true;
	}
	return false;
}

double getN(const double m) {
	if (m < 0 || m > 0.5) return -1;
	//initialize opertor i
	double i = 0.25;
	double dividor = 0.125;
	double area = PI * m;
	//control sol in [i, i+dividor]
	for (int t = 0; t < 21; t++) {
		if (shouldBeLargerOrNot(i, area)) {
			i += dividor;
		}
		else {
			i -= dividor;
		}
		dividor = dividor / 2;
	}
	return i;
}
// In general, ignore this file, but keep it around if you are using pre-compiled headers.
