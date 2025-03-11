#include <iostream>
#define MAX 97
using namespace std;

int t[MAX];
int N, P;

void func() {
	if (N < MAX) {
		t[N] = 1;
	}

	int x = N;
	int cnt = 2;
	while (1) {
		x = (x * N) % P;
		if (t[x]) {
			cout << cnt - t[x] << '\n';
			return;
		}
		t[x] = cnt++;
	}
}

void input() {
	cin >> N >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}