#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
typedef vector<vector<int> > vvi;

vvi v;
int N, M, P;

vvi calMatrix(vvi x, vvi y) {
	vvi ret(N);
	for (int i = 0; i < N; i++) ret[i].resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % M;
			}
		}
	}
	return ret;
}

vvi power(int t) {
	vvi ret(N);
	for (int i = 0; i < N; i++) {
		ret[i].resize(N);
		ret[i][i] = 1;
	}

	while (t) {
		if (t & 1) ret = calMatrix(ret, v);
		v = calMatrix(v, v);
		t >>= 1;
	}

	return ret;
}

void func() {
	vvi ret = power(P);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	v.clear();
}

void input() {
	int x;
	cin >> N >> M >> P;
	if (!N || !M || !P) exit(0);

	for (int i = 0; i < N; i++) {
		v.push_back({});
		for (int j = 0; j < N; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}