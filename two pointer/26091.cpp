#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, M;

void func() {
	sort(list, list + N);
	int l = 0;
	int r = N - 1;

	int ret = 0;
	while (l < r) {
		if (list[l] + list[r] >= M) {
			ret++;
			l++;
			r--;
		}
		else {
			l++;
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