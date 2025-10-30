#include <iostream>
#define NOS 5
using namespace std;

int N, L, D;

void func() {
	int t = D;
	int total = N * L + (N - 1) * NOS;
	while (1) {
		if (t > total) break;
		if (t % (L + NOS) >= L) break;
		t += D;
	}

	cout << t << '\n';
}

void input() {
	cin >> N >> L >> D;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}