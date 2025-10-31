#include <iostream>
#define MAX 5
#define NUM 10
using namespace std;

int cnt[NUM];

void func() {
	for (int i = 0; i < NUM; i++) {
		if (cnt[i] & 1) {
			cout << i << '\n';
			return;
		}
	}
}

void input() {
	int x;
	for (int i = 0; i < MAX; i++) {
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