#include <iostream>
#define PI 3.1415926535897932384626433832795028
using namespace std;

double a, p1, r, p2;

void func() {
	double ret1 = a / p1;
	double ret2 = r * r * PI / p2;

	if (ret1 > ret2) {
		cout << "Slice of pizza\n";
	}
	else {
		cout << "Whole pizza\n";
	}
}

void input() {
	cin >> a >> p1 >> r >> p2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}