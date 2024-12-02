#include <iostream>
#include <algorithm>
#define MAX 3001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = -1;
	int diff = 0;
	for (int i = 1; i < N; i++) {
		int m = (list[i] + list[i - 1]) >> 1;
		if (list[i - 1] == m) continue;
		if (m - list[i - 1] > diff) {
			diff = m - list[i - 1];
			ret = m;
		}
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