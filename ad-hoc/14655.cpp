#include <iostream>
#define MAX 10001
using namespace std;

int list[2][MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[0][i] - list[1][i]);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[0][i];
		if (list[0][i] < 0) list[0][i] = -list[0][i];
	}

	for (int i = 0; i < N; i++) {
		cin >> list[1][i];
		if (list[1][i] > 0) list[1][i] = -list[1][i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}