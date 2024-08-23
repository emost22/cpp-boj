#include <iostream>
#define MAX 1000002
using namespace std;

int list[MAX];
int N, M;

int getFlip() {
	int ret = 0;
	int pre = -1;
	for (int i = 1; i <= N; i++) {
		if (!list[i]) {
			if (pre == 1) ret++;
		}
		
		pre = list[i];
	}
	return ret + (pre == 1);
}

void func() {
	int type, idx;
	int ret = getFlip();
	while (M--) {
		cin >> type;
		if (type) {
			cin >> idx;
			if (list[idx]) continue;

			list[idx] = 1;
			if (list[idx - 1] == list[idx + 1]) {
				if (!list[idx - 1]) ret++;
				else ret--;
			}
		}
		else {
			cout << ret << '\n';
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
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