#include <iostream>
#define MAX 2000001
using namespace std;

int cnt[MAX];
int N;

void func() {
	for (int i = 0; i < MAX; i++) {
		while (cnt[i]--) {
			cout << i - 1000000 << '\n';
		}
	}
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x + 1000000]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}