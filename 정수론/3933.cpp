#include <iostream>
#include <math.h>
using namespace std;

int cnt;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	while (1) {
		cin >> N;
		if (!N) break;

		for (int i = 1; i*i <= N; i++) {
			if (i * i == N) cnt++;
			for (int j = i; i * i + j * j <= N; j++) {
				if (i * i + j * j == N) cnt++;
				for (int k = j; i * i + j * j + k * k <= N; k++) {
					if (i * i + j * j + k * k == N) cnt++;

					int d = N - (i * i + j * j + k * k);
					if ((int)sqrt(d) * (int)sqrt(d) == N - (i * i + j * j + k * k) && k * k <= d) {
						cnt++;
					}
				}
			}
		}

		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}