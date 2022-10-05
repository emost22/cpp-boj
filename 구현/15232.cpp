#include <iostream>
using namespace std;

int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "*";
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}