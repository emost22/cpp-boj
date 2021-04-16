#include <iostream>
using namespace std;

bool d[257][257];
int N, M;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] && d[k][j]) d[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int l = 1;
		int r = N;
		for (int j = 1; j <= N; j++) {
			if (d[i][j] && d[j][i]) {
				cout << "-1\n";
				return;
			}

			if (d[i][j]) r--;
			else if (d[j][i]) l++;
		}
	}

	for (int i = 1; i <= N; i++) {
		int l = 1;
		int r = N;
		for (int j = 1; j <= N; j++) {
			if (d[i][j]) r--;
			else if (d[j][i]) l++;
		}

		cout << l << ' ' << r << '\n';
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		d[u][v] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}