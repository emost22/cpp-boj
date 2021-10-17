#include <iostream>
#include <algorithm>
#define MAX 10000
#define INF 1000000000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = INF;
	for (int i = 0; i < N / 2; i++) {
		ans = min(ans, list[i] + list[N - 1 - i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	N *= 2;
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