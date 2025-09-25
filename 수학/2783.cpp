#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

double list[MAX];
int N;

void func() {
	cout << fixed;
	cout.precision(3);

	double ret = 1e9;
	for (int i = 0; i < N; i++) {
		ret = min(ret, list[i]);
	}
	cout << ret * 1000.0 << '\n';
}

void input() {
	double x, y;
	cin >> x >> y >> N;
	list[0] = x / y;
	N++;

	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		list[i] = x / y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}