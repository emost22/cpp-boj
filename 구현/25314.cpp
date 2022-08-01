#include <iostream>
using namespace std;

int N;

void func() {
	for (int i = 0; i < N; i += 4) {
		cout << "long ";
	}
	cout << "int\n";
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