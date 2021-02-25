#include <iostream>
using namespace std;

int list[7][2];
int N, K, ans;

void func() {
	for (int i = 1; i <= 6; i++) {
		if (list[i][0]) ans++;
		if (list[i][1]) ans++;
	}

	cout << ans << '\n';
}

void input() {
	int s, y;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s >> y;
		list[y][s]++;
		if (list[y][s] == K) {
			ans++;
			list[y][s] = 0;
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