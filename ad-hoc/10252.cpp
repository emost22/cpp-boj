#include <iostream>
using namespace std;

int N, M;

void func() {
	cout << "1\n";
	cout << "(0,0)\n";
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			for (int j = M - 1; j > 0; j--) {
				cout << '(' << i << ',' << j << ")\n";
			}
		}
		else {
			for (int j = 1; j < M; j++) {
				cout << '(' << i << ',' << j << ")\n";
			}
		}
	}

	for (int i = N - 1; i > 0; i--) {
		cout << '(' << i << ",0)\n";
	}
}

void input() {
	cin >> N >> M;
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