#include <iostream>
#define MAX 100001
using namespace std;

int list[MAX];
int N;

int getMaxIdx(int s) {
	int maxValue = list[s];
	int idx = s;
	for (int i = s + 1; i < N; i++) {
		if (maxValue <= list[i]) {
			maxValue = list[i];
			idx = i;
		}
	}
	return idx;
}

void func() {
	int ret = 0;
	int s = 0;
	while (s < N) {
		int e = getMaxIdx(s);
		int cnt = 0;
		for (int i = s; i < e; i++) {
			ret -= list[i];
			cnt++;
		}

		ret += (list[e] * cnt);
		s = e + 1;
	}
	cout << ret << '\n';
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