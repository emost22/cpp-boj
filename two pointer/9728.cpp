#include <iostream>
#define MAX 20001
using namespace std;

int list[MAX];
int N, M;

void func(int tc) {
	int l = 0;
	int r = N - 1;
	int ret = 0;
	while (l < r) {
		int sum = list[l] + list[r];
		if (sum >= M) {
			r--;
			if (sum == M) {
				ret++;
			}
		}
		else if (sum < M) {
			l++;
		}
	}

	cout << "Case #" << tc << ": " << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}