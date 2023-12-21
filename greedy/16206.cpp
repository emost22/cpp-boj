#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N, M;

bool cmp(int a, int b) {
	if (!(a % 10) && !(b % 10)) return a < b;
	else if (!(a % 10)) return true;
	else if (!(b % 10)) return false;
	else return a < b;
}

void func() {
	sort(list, list + N, cmp);

	int ret = 0;
	int cnt = M;
	for (int i = 0; i < N; i++) {
		if (!(list[i] % 10)) {
			while (cnt && list[i] > 10) {
				cnt--;
				ret++;
				list[i] -= 10;
			}

			if (list[i] == 10) ret++;
		}
		else {
			while (cnt && list[i] > 10) {
				cnt--;
				ret++;
				list[i] -= 10;
			}
		}
	}

	cout << ret << '\n';
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