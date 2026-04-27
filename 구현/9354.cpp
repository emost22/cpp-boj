#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;

char type[MAX];
ll list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		if (type[i] == 'T') continue;
		list[i] = -list[i];
	}

	ll ret = 0;
	for (int i = N - 1; i >= 0; i--) {
		ret = max(0LL, ret + list[i]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> type[i];
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