#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N, M;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int x = list[0];
	for (int i = 1; i < N; i++) {
		x = gcd(x, list[i]);
	}

	cout << x << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		list[i] = abs(list[i] - M);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}