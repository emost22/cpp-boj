#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> v1, v2;
int list[2][MAX];
int N, M, K;

void func() {
	v1.push_back(0);
	v2.push_back(0);

	bool flag = true;
	for (int i = 0; i < N; i++) {
		int sum = list[0][i];
		v1.push_back(sum);
		for (int j = (i + 1) % N; j != i; j = (j + 1) % N) {
			sum += list[0][j];
			if (sum > K) break;

			if ((i == 0 && j == N - 1) || j == i - 1) {
				if (!flag) break;

				flag = false;
			}
			v1.push_back(sum);
		}
	}

	flag = true;
	for (int i = 0; i < M; i++) {
		int sum = list[1][i];
		v2.push_back(sum);
		for (int j = (i + 1) % M; j != i; j = (j + 1) % M) {
			sum += list[1][j];
			if (sum > K) break;

			if ((i == 0 && j == M - 1) || j == i - 1) {
				if (!flag) break;

				flag = false;
			}
			v2.push_back(sum);
		}
	}
	sort(v2.begin(), v2.end());

	int vsize = v1.size();
	int ans = 0;
	for (int i = 0; i < vsize; i++) {
		ans += (upper_bound(v2.begin(), v2.end(), K - v1[i]) - lower_bound(v2.begin(), v2.end(), K - v1[i]));
	}

	cout << ans << '\n';
}

void input() {
	cin >> K >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[0][i];
	}

	for (int i = 0; i < M; i++) {
		cin >> list[1][i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}