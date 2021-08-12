#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
bool visit[26];

void input() {
	int ans = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		visit[str[i] - 'A'] = true;
	}

	for (int i = 0; i < 26; i++) {
		if (!visit[i]) ans += (i + 'A');
	}

	cout << ans << '\n';
	memset(visit, false, sizeof(visit));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}