#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = list[0];
	for (int i = 1; i < N; i += 2) {
		ret += (-list[i] + list[i + 1]);
	}
	ret >>= 1;

	cout << ret << '\n';
	for (int i = 0; i < N - 1; i++) {
		ret = list[i] - ret;
		cout << ret << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}