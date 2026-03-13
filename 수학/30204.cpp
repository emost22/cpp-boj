#include <iostream>
using namespace std;

int N, X, sum;

void func() {
	if (sum % X) cout << "0\n";
	else cout << "1\n";
}

void input() {
	cin >> N >> X;

	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		sum += a;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}