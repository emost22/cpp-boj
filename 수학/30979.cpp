#include <iostream>
using namespace std;

int T, N;
int sum;

void func() {
	cout << (sum >= T ? "Padaeng_i Happy\n" : "Padaeng_i Cry\n");
}

void input() {
	cin >> T >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		sum += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}