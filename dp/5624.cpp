#include <iostream>
using namespace std;

bool visit[400001];
int list[5000];
int N, ans;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (visit[list[i] - list[j] + 200000]) {
				ans++;
				break;
			}
		}

		for (int j = 0; j <= i; j++) {
			visit[list[i] + list[j] + 200000] = true;
		}
	}

	cout << ans << '\n';
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