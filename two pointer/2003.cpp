#include <iostream>
using namespace std;

int list[10000], s, e, sum, cnt;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	while (1) {
		if (sum >= M) sum -= list[s++];
		else if (e == N) break;
		else sum += list[e++];

		if (sum == M) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}