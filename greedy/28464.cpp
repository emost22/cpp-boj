#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int l = 0;
	int r = N - 1;
	int ret1 = 0;
	int ret2 = 0;
	while (l < r) {
		ret1 += list[r--];
		ret2 += list[l++];
	}
	if (N & 1) ret1 += list[r];

	cout << ret2 << ' ' << ret1 << '\n';
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