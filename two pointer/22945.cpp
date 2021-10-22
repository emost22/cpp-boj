#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N;

void func() {
	int l = 0;
	int r = N - 1;
	int ans = 0;
	while (l < r) {
		ans = max(ans, (r - l - 1)*min(list[l], list[r]));

		if (list[l] > list[r]) r--;
		else l++;
	}

	cout << ans << '\n';
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