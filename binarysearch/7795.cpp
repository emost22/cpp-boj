#include <iostream>
#include <algorithm>
#define MAX 20000
using namespace std;

int aList[MAX], bList[MAX];
int N, M;

int binarySearch(int x) {
	int l = 0;
	int r = M - 1;
	while (l <= r) {
		int m = (l + r) / 2;

		if (x > bList[m]) l = m + 1;
		else r = m - 1;
	}

	return l;
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += binarySearch(aList[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> aList[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> bList[i];
	}
	sort(aList, aList + N);
	sort(bList, bList + M);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}