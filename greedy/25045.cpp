#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef long long ll;

ll a[MAX], b[MAX];
int N, M;

void func() {
	sort(a, a + N, [](int x, int y) {
		return x > y;
	});
	sort(b, b + M);

	ll ret = 0;
	for (int i = 0; i < M; i++) {
		if (a[i] <= b[i]) break;
		ret += (a[i] - b[i]);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}