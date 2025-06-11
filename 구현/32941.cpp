#include <iostream>
using namespace std;

int T, X, N;
int cnt;

void func() {
	cout << (cnt == N ? "YES\n" : "NO\n");
}

void input() {
	cin >> T >> X >> N;
	
	int M, a;
	for (int i = 0; i < N; i++) {
		cin >> M;
		while (M--) {
			cin >> a;
			cnt += (a == X);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}