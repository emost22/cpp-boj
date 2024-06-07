#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int cnt[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		ret += min(cnt[i], 2);
	}
	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}