#include <iostream>
#include <algorithm>
#define MAX 2001
using namespace std;

int cnt[MAX];
int N;

void func() {
	for (int i = 0; i < MAX; i++) {
		if (cnt[i]) cout << i - 1000 << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x + 1000]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}