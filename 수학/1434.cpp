#include <iostream>
#define MAX 50
using namespace std;

int a[MAX], b[MAX];
int N, M;

void func() {
	int idx = 0;
	int ret = 0;
	for (int i = 0; i < M; i++) {
		while (idx < N) {
			if (a[idx] < b[i]) {
				ret += a[idx];
				idx++;
				continue;
			}

			a[idx] -= b[i];
			break;
		}
	}

	while (idx < N) {
		ret += a[idx++];
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