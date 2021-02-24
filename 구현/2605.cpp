#include <iostream>
using namespace std;

int list[101], ans[101];
int N;

void print() {
	for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
	cout << '\n';
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (!list[i]) {
			ans[i] = i;
			continue;
		}
		int cnt = list[i];
		for (int j = i; cnt; j--, cnt--) {
			ans[j] = ans[j - 1];
		}
		ans[i - list[i]] = i;
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	print();

	return 0;
}