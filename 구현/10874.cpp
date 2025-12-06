#include <iostream>
#define MAX_N 101
#define MAX_M 11
using namespace std;

int list[MAX_N][MAX_M];
int ans[MAX_M];
int N;

void init() {
	for (int i = 1; i < MAX_M; i++) {
		ans[i] = (i - 1) % 5 + 1;
	}
}

void func() {
	init();

	for (int i = 1; i <= N; i++) {
		bool flag = true;
		for (int j = 1; j < MAX_M; j++) {
			if (ans[j] == list[i][j]) continue;
			
			flag = false;
			break;
		}

		if (flag) cout << i << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < MAX_M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}