#include <iostream>
#include <vector>
#define MAX 36
using namespace std;

char list[5][MAX];
char num[10][5][3] = {
	{ {'#','#','#'},{'#','.','#'},{'#','.','#'},{'#','.','#'},{'#','#','#'} },
	{ {'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'} },
	{ {'#','#','#'},{'.','.','#'},{'#','#','#'},{'#','.','.'},{'#','#','#'} },
	{ {'#','#','#'},{'.','.','#'},{'#','#','#'},{'.','.','#'},{'#','#','#'} },
	{ {'#','.','#'},{'#','.','#'},{'#','#','#'},{'.','.','#'},{'.','.','#'} },
	{ {'#','#','#'},{'#','.','.'},{'#','#','#'},{'.','.','#'},{'#','#','#'} },
	{ {'#','#','#'},{'#','.','.'},{'#','#','#'},{'#','.','#'},{'#','#','#'} },
	{ {'#','#','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'} },
	{ {'#','#','#'},{'#','.','#'},{'#','#','#'},{'#','.','#'},{'#','#','#'} },
	{ {'#','#','#'},{'#','.','#'},{'#','#','#'},{'.','.','#'},{'#','#','#'} }
};
int N, mul = 1;

void func() {
	vector<int> v[10];
	vector<int> vsize;

	int sj = 0;
	for (int t = 0; t < N; t++) {
		for (int k = 0; k < 10; k++) {
			bool flag = false;
			for (int i = 0; i < 5; i++) {
				for (int j = sj, y = 0; j < sj + 3; j++, y++) {
					if (list[i][j] == num[k][i][y]) continue;
					if (list[i][j] == '#') {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}

			if (!flag) {
				v[t].push_back(k);
			}
		}

		if (v[t].empty()) {
			cout << "-1\n";
			return;
		}
		vsize.push_back(v[t].size());
		sj += 4;
	}
	double d = 1;
	for (int i = 0; i < N; i++) {
		d *= vsize[i];
	}

	double ans = 0;
	double m = mul;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			ans += (v[i][j] * d / vsize[i] * m);
		}
		m /= 10;
	}

	cout << fixed; cout.precision(5);
	cout << ans / d << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) mul *= 10;
	for (int i = 0; i < 5; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}