#include <iostream>
#define MAX 120
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = list[N - 1];
	for (int i = 0; i < N - 1; i++) {
		ret += (list[i] + 8);
	}
	cout << ret / 24 << ' ' << ret % 24 << '\n';
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