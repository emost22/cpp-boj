#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += abs(i - list[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	sort(list + 1, list + 1 + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}