#include <iostream>
#define MAX 100001
using namespace std;

int list[MAX];
bool chk[MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		list[i] = i;
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (chk[list[i]]) {
			cout << "-1\n";
			return;
		}
		chk[list[i]] = true;
	}

	for (int i = 1; i <= N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> x >> y;
		list[x]++;
		list[y]--;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}