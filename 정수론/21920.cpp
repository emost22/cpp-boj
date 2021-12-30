#include <iostream>
#define MAX 500000
using namespace std;

int list[MAX];
int N, X;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (gcd(list[i], X) != 1) continue;

		sum += list[i];
		cnt++;
	}

	cout << sum / cnt << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> X;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}