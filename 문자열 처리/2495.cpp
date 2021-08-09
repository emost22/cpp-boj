#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N;

void input() {
	cin >> str;
	N = str.size();

	int ans = 1;
	int now = 1;
	for (int i = 1; i < N; i++) {
		if (str[i] == str[i - 1]) {
			now++;
		}
		else now = 1;

		ans = max(ans, now);
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++) {
		input();
	}

	return 0;
}