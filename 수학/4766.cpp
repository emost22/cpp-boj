#include <iostream>
#include <vector>
using namespace std;

vector<double> v;

void func() {
	cout << fixed;
	cout.precision(2);

	for (int i = 1; i < v.size(); i++) {
		cout << v[i] - v[i - 1] << '\n';
	}
}

void input() {
	double x;
	while (1) {
		cin >> x;
		if (x == 999.0) break;
		v.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}