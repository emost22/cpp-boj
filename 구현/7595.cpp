#include <iostream>
using namespace std;

int N;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		if (!N) return 0;

		func();
	}
}