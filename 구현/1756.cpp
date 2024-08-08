#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;

int width[MAX];
int list[MAX];
int N, M;

void func() {
	int idx = N;
	for (int i = 0; i < M; i++) {
		bool flag = false;
		while (idx > 0) {
			if (width[idx] >= list[i]) {
				idx--;
				flag = true;
				break;
			}
			idx--;
		}
		if (!flag) {
			cout << "0\n";
			return;
		}
	}
	cout << idx + 1 << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> width[i];
		if (i > 1) {
			width[i] = min(width[i], width[i - 1]);
		}
	}

	for (int i = 0; i < M; i++) {
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