#include <iostream>
#include <cmath>
using namespace std;

double D, H, W;

void func() {
	double m = sqrt(D * D / (H * H + W * W));
	cout << (int)(m * H) << ' ' << (int)(m * W) << '\n';
}

void input() {
	cin >> D >> H >> W;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}