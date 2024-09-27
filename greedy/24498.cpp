#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = max(list[0], list[N - 1]);
	for (int i = 1; i < N - 1; i++) {
		ret = max(ret, list[i] + min(list[i - 1], list[i + 1]));
	}
	cout << ret << '\n';
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