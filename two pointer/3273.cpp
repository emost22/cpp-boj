#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N, x;

void func() {
	int l = 0;
	int r = N - 1;
	int ans = 0;
	
	while (l < r) {
		if (list[l] + list[r] == x) {
			ans++;
			l++;
			r--;
		}
		else if (list[l] + list[r] > x) r--;
		else l++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> x;
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}