#include <iostream>
#define MAX 200000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int l = 0;
	while (M--) {
		int type;
		cin >> type;

		if (type == 1) {
			int idx, x;
			cin >> idx >> x;
			list[(idx - 1 + l) % N] += x;
		}
		else if (type == 2) {
			int s;
			cin >> s;
			l = (l - s + N) % N;
		}
		else {
			int s;
			cin >> s;
			l = (l + s) % N;
		}
	}

	for (int cnt = 0; cnt < N; cnt++, l = (l + 1) % N) {
		cout << list[l] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
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