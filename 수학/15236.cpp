#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			ret += (i + j);
		}
	}

	cout << ret << '\n';
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