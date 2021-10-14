#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str, ans;
int N;

void func() {
	int a = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (str[i] == 'B') a++;
		if (ans[i] == 'B') a--;

		if (str[i] != ans[i]) cnt++;
	}

	cout << abs(a) + (cnt - abs(a)) / 2 << '\n';
}

void input() {
	cin >> N >> str >> ans;
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