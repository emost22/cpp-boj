#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, L;

void func() {
	cout << min(x, (N / L) * (M / L)) << '\n';
}

void input() {
	cin >> x >> N >> M >> L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}