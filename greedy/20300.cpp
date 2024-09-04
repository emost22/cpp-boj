#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	sort(list, list + N);
	ll ret = 0;
	int l = 0;
	int r = N - 1;
	if (N & 1) {
		ret = list[N - 1];
		r--;
	}

	while (l < r) {
		ret = max(ret, list[l++] + list[r--]);
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