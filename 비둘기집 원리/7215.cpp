#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int k, N;

void func() {
	int ret = 0;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		ret += min(k - 1, list[i]);
		if (k <= list[i]) flag = true;
	}

	if (flag) cout << ret + 1 << '\n';
	else cout << "-1\n";
}

void input() {
	cin >> k >> N;
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