#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int ans = 1;
	int s = list[0] + M - 1;
	for (int i = 1; i < N; i++) {
		if (s < list[i]) {
			s = list[i] + M - 1;
			ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}