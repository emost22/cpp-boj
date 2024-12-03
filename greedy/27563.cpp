#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len;

void func() {
	int cnt = 3;
	for (int i = 0; i < len - 2; i++) {
		string tmp = str.substr(i, 3);
		if (tmp == "MOO") {
			cout << len - 3 << '\n';
			return;
		}
		else if (tmp == "MOM" || tmp == "OOO") cnt = 1;
		else if (tmp == "OOM") cnt = min(cnt, 2);
	}
	if (cnt == 3) cout << "-1\n";
	else cout << len - 3 + cnt << '\n';
}

void input() {
	cin >> str;
	len = str.size();
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