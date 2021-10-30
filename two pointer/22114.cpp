#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N, K;

void func() {
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		bool flag = false;
		int cnt = 0;
		for (int j = i; j < N - 1; j++) {
			if (list[j] > K) {
				if (flag) break;
				flag = true;
			}

			cnt++;
		}
		
		ans = max(ans, cnt);
	}

	cout << ans + 1 << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
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