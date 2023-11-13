#include <iostream>
#include <algorithm>
#define MAX_M 1001
#define MAX_N 10
using namespace std;

int cnt[MAX_M];
int list[MAX_N];

void func() {
	int sum = 0;
	int maxCnt = 0;
	int idx = 0;
	for (int i = 0; i < MAX_N; i++) {
		sum += list[i];
		cnt[list[i]]++;
		if (maxCnt < cnt[list[i]]) {
			maxCnt = cnt[list[i]];
			idx = list[i];
		}
	}

	cout << sum / 10 << '\n' << idx << '\n';
}

void input() {
	for (int i = 0; i < MAX_N; i++) {
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