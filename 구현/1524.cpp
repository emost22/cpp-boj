#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int sj[MAX], sb[MAX];
int N, M;

void func() {
	sort(sj, sj + N);
	sort(sb, sb + M);

	int j = 0;
	int b = 0;
	while (1) {
		if (j == N) {
			cout << "B\n";
			return;
		}

		if (b == M) {
			cout << "S\n";
			return;
		}

		if (sj[j] < sb[b]) j++;
		else b++;
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> sj[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> sb[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}