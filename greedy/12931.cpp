#include <iostream>
#define MAX 51
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	while (1) {
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (list[i] & 1) {
				ret++;
				list[i]--;
			}

			flag |= list[i];
			list[i] >>= 1;
		}
		if (flag) ret++;

		flag = false;
		for (int i = 0; i < N; i++) {
			flag |= list[i];
		}

		if (!flag) {
			cout << ret << '\n';
			return;
		}
	}
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