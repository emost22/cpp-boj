#include <iostream>
#include <algorithm>
#include <string>
#define MAX 100001
using namespace std;

string list[MAX];
int N;

int getDis(string a, string b) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		ret += (a[i] != b[i]);
	}

	return ret;
}

void func() {
	if (N > 32) {
		cout << "0\n";
		return;
	}

	int ans = 1e9;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				ans = min(ans, getDis(list[i], list[j]) + getDis(list[i], list[k]) + getDis(list[j], list[k]));
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}