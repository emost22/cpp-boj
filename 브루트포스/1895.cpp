#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 41
using namespace std;

int list[MAX][MAX];
int N, M, T;

int getMiddleNumber(int x, int y) {
	vector<int> v;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			v.push_back(list[i][j]);
		}
	}

	sort(v.begin(), v.end());
	return v[4];
}

void func() {
	int ret = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			ret += (getMiddleNumber(i, j) >= T);
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
	cin >> T;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}