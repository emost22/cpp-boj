#include <iostream>
using namespace std;

int N;

void func() {
	for (int i = 1; i <= N; i++) {
		if (!(i % 7) && !(i % 11)) cout << "Wiwat!\n";
		else if (!(i % 7)) cout << "Hurra!\n";
		else if (!(i % 11)) cout << "Super!\n";
		else cout << i << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}