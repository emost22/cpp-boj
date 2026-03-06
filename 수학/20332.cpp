#include <iostream>
using namespace std;

int N, sum;

void func() {
	if (sum % 3) cout << "no\n";
	else cout << "yes\n";
}

void input() {
	cin >> N;

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