#include <iostream>
#include <algorithm>
#define MAX_N 1<<21
#define MAX_M 200000
using namespace std;

bool visit[MAX_N];
int list[MAX_M];
int N, M;

void func() {
	for (int i = 0; i < M; i++) {
		int v = 1e9;
		for (int j = list[i]; j > 0; j /= 2) {
			if (visit[j]) v = min(v, j);
		}

		if (v == 1e9) {
			visit[list[i]] = true;
			cout << "0\n";
		}
		else {
			cout << v << '\n';
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
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