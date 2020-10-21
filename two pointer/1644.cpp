#include <iostream>
using namespace std;
typedef long long ll;

bool chk[4000001];
int prime[283147], pindex, s, e, cnt;
ll sum;

void sosu(int N) {
	for (int i = 2; i <= N; i++) {
		if (chk[i]) continue;
		prime[pindex++] = i;
		for (int j = 2; i * j <= N; j++) {
			if (chk[i * j]) continue;
			chk[i * j] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	sosu(N);

	while (1) {
		if (sum >= N) sum -= prime[s++];
		else {
			if (e == pindex) break;
			else sum += prime[e++];
		}

		if (sum == N) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}