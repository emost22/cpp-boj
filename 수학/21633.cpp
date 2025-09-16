#include <iostream>
#include <algorithm>
#define BASIC 25.0
#define FEE 0.01
#define MIN 100.0
#define MAX 2000.0
using namespace std;

double x;

void func() {
	cout << fixed;
	cout.precision(2);
	cout << max(MIN, min(MAX, BASIC + x * FEE)) << '\n';
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}