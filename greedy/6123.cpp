#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, L, K;

void func() {
	sort(list, list + N);

	int ret = 0;
	int now = L;
	for (int i = 0; i < N; i++) {
		if (now < list[i]) break;
		now += K;
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> L >> K;
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