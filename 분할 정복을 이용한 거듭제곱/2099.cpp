#include <iostream>
#include <vector>
#define MAX 201
using namespace std;
typedef vector<vector<bool> > vvb;

vvb v;
int N, M, K;

vvb calMatrix(vvb x, vvb y) {
	vvb ret(N + 1, vector<bool>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (!x[i][k] || !y[k][j]) continue;
				ret[i][j] = true;
			}
		}
	}
	return ret;
}

vvb power(vvb x, int t) {
	vvb ret(N + 1, vector<bool>(N + 1));
	for (int i = 1; i <= N; i++) {
		ret[i][i] = true;
	}

	while (t) {
		if (t & 1) ret = calMatrix(ret, x);
		x = calMatrix(x, x);
		t >>= 1;
	}

	return ret;
}

void func() {
	int a, b;
	while (M--) {
		cin >> a >> b;
		if (v[a][b]) cout << "death\n";
		else cout << "life\n";
	}
}

void input() {
	int x, y;
	cin >> N >> K >> M;
	v.resize(N + 1, vector<bool>(N + 1));
	vvb tmp(N + 1, vector<bool>(N + 1));
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		tmp[i][x] = true;
		tmp[i][y] = true;
	}
	v = power(tmp, K);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}