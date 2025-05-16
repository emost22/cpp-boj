#include <iostream>
#define MAX 50
using namespace std;
typedef long long ll;

int list[MAX];
int N;

ll ccw(ll x, ll y, ll z) {
	return x * (list[y] - list[z]) + y * (list[z] - list[x]) + z * (list[x] - list[y]);
}

void func() {
	if (N < 3) {
		cout << N - 1 << '\n';
		return;
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		if (i > 0) {
			int pre = i - 1;
			cnt++;
			for (int j = i - 2; j >= 0; j--) {
				if (ccw(i, pre, j) >= 0) continue;
				cnt++;
				pre = j;	
			}
		}

		if (i < N - 1) {
			int pre = i + 1;
			cnt++;
			for (int j = i + 2; j < N; j++) {
				if (ccw(i, pre, j) <= 0) continue;
				cnt++;
				pre = j;
			}
		}

		ret = max(ret, cnt);
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