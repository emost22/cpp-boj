#include <iostream>
#include <algorithm>
#define MAX 3001
using namespace std;

int pos[MAX], t[MAX];
int N;

void func() {
	int ret = max(t[N - 1], pos[N - 1]);

	for (int i = N - 2; i >= 0; i--) {
		ret = max(ret + pos[i + 1] - pos[i], t[i]);
	}
	ret += pos[0];

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}