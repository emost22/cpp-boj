#include <iostream>
#include <string>
using namespace std;

string s, p;
int sLen, pLen;

void func() {
	int ret = 0;
	int idx = 0;
	while (idx < sLen) {
		if (idx + pLen > sLen) {
			ret += (sLen - idx);
			break;
		}

		bool flag = true;
		for (int i = 0; i < pLen && i + idx < sLen; i++) {
			if (s[i + idx] != p[i]) {
				flag = false;
				break;
			}
		}

		if (flag) idx += pLen;
		else idx++;
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> s >> p;
	sLen = s.size();
	pLen = p.size();
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