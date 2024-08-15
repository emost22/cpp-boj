#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N;

void func() {
	int l = 0;
	int ret = 1;
	while (l < N) {
		int r = l;
		if (r + 1 < N && list[l] == list[r + 1]) r++;

		int s = l - 1;
		int e = r + 1;
		while (s >= 0 && e < N) {
			if (list[s] != list[e] || list[s] >= list[s + 1]) break;
			e++;
			s--;
		}

		ret = max(ret, e - s - 1);
		l = e;
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