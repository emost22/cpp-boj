#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N, D, M, len;

void func() {
	int h = 0;
	int y = 0;
	int u = 0;
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] != 'H' && str[i] != 'Y' && str[i] != 'U') {
			cnt++;
			continue;
		}

		if (cnt) {
			ret += min(D * cnt, D + M);
			cnt = 0;
		}

		if (str[i] == 'H') h++;
		else if (str[i] == 'Y') y++;
		else u++;
	}
	if (cnt) ret += min(D * cnt, D + M);

	if (ret) cout << ret << '\n';
	else cout << "Nalmeok\n";

	if (!h || !y || !u) cout << "I love HanYang University\n";
	else cout << min({ h, y, u }) << '\n';
}

void input() {
	cin >> N >> str >> D >> M;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}