#include <iostream>
#include <vector>
using namespace std;

int P, Q;

void getDiv(vector<int>& v, int x) {
	for (int i = 1; i <= x; i++) {
		if (x % i) continue;
		v.push_back(i);
	}
}

void func() {
	vector<int> p, q;
	getDiv(p, P);
	getDiv(q, Q);

	for (auto a : p) {
		for (auto b : q) {
			cout << a << ' ' << b << '\n';
		}
	}
}

void input() {
	cin >> P >> Q;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}