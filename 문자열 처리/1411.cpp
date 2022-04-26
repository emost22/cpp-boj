#include <iostream>
#include <string>
#include <cstring>
#define MAX_N 101
#define MAX_M 51
using namespace std;

bool used[MAX_N];
int visit1[MAX_M], visit2[MAX_M];
string list[MAX_N];
int N, M;

int charToInt(char x, char k) {
	if (k >= x) return k - x;
	else return k - x + 26;
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		used[i] = true;
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (used[j]) continue;
			bool flag = true;
			memset(visit1, -1, sizeof(visit1));
			memset(visit2, -1, sizeof(visit2));
			for (int k = 0; k < M; k++) {
				int x = list[i][k] - 'a';
				int y = list[j][k] - 'a';
				if (visit1[x] != -1 && visit1[x] != y) {
					flag = false;
					break;
				}

				if (visit2[y] != -1 && visit2[y] != x) {
					flag = false;
					break;
				}

				visit1[x] = y;
				visit2[y] = x;
			}

			if (flag) {
				cnt++;
				used[j] = true;
			}
		}

		ans += (cnt * (cnt - 1) / 2);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	M = list[0].size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}