#include <iostream>
#define MAX 100001
using namespace std;

int cnt[MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << '\n';
	}
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		cnt[x]++;
		cnt[y]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}