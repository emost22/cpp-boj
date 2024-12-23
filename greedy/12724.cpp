#include <iostream>
#include <algorithm>
#define MAX 801
using namespace std;
typedef long long ll;

ll list[2][MAX];
int N;

void func(int tc) {
	sort(list[0], list[0] + N);
	sort(list[1], list[1] + N, [](int a, int b) {
		return a > b;
	});

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[0][i] * list[1][i]);
	}
	cout << "Case #" << tc << ": " << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}