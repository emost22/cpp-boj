#include <iostream>
#include <vector>
#define MAX_N 45
#define MAX_K 1001
using namespace std;

vector<int> v;
int chk[MAX_K];
int N;

void init() {
	for (int i = 1; i <= MAX_N; i++) {
		v.push_back(i * (i + 1) >> 1);
	}

	for (auto x : v) {
		for (auto y : v) {
			if (x + y >= 1000) break;
			for (auto z : v) {
				if (x + y + z > 1000) break;
				chk[x + y + z] = 1;
			}
		}
	}
}

void func() {
	cout << chk[N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}