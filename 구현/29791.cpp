#include <iostream>
#define MAX 1000001
#define ATIME 100
#define BTIME 360
using namespace std;

bool a[MAX], b[MAX];
int N, M;

int skill(bool* s, int t) {
	int wait = 0;
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		if (!s[i]) continue;
		if (i < wait) continue;
		wait = i + t;
		ret++;
	}

	return ret;
}

void func() {
	cout << skill(a, ATIME) << ' ' << skill(b, BTIME) << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a[x] = true;
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
		b[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}