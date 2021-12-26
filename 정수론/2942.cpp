#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;
int x, y;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int g = gcd(x, y);
	for (int i = 1; i * i <= g; i++) {
		if (g % i) continue;

		list.push_back(i);
		if (i != g / i) list.push_back(g / i);
	}

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << ' ' << x / list[i] << ' ' << y / list[i] << '\n';
	}
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}