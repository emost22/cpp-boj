#include <iostream>
#include <algorithm>
#define MAX 2000
using namespace std;

int list[MAX];
int N;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	for (int i = 0; i < N - 1; i++) {
		list[i] = abs(list[i] - list[i + 1]);
	}

	int x = list[0];
	for (int i = 1; i < N - 1; i++) {
		x = gcd(x, list[i]);
	}

	if (!x) cout << "INFINITY\n";
	else cout << x << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}