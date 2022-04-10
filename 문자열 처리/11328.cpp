#include <iostream>
#include <string>
#include <cstring>
#define MAX 26
using namespace std;

string x, y;
int cnt[MAX];
int N, M;

void func() {
	memset(cnt, 0, sizeof(cnt));
	if (N != M) {
		cout << "Impossible\n";
		return;
	}
	
	for (int i = 0; i < N; i++) {
		cnt[x[i] - 'a']++;
	}

	for (int i = 0; i < M; i++) {
		if (!cnt[y[i] - 'a']) {
			cout << "Impossible\n";
			return;
		}
		cnt[y[i] - 'a']--;
	}

	cout << "Possible\n";
}

void input() {
	cin >> x >> y;
	N = x.size();
	M = y.size();
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