#include <iostream>
using namespace std;

int S, N, M;

void func() {
	int t = N + M;
	int x;
	int sz = S;
	int now = 0;
	while (t--) {
		cin >> x;
		if (x) {
			if (now == sz) {
				sz <<= 1;
			}
			now++;
		}
		else {
			now--;
		}
	}
	cout << sz << '\n';
}

void input() {
	cin >> S >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}