#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> ans;
string str;
int N, len;

void func() {
	map<string, int>::iterator iter = ans.begin();
	for (; iter != ans.end(); iter++) {
		cout << (*iter).first << ' ' << (*iter).second << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		len = str.size();
		bool flag = false;
		string tmp = "";
		for (int j = 0; j < len; j++) {
			if (str[j] == '.') {
				flag = true;
				continue;
			}

			if (flag) {
				tmp += str[j];
			}
		}

		if (ans.find(tmp) == ans.end()) {
			ans.insert({ tmp, 1 });
		}
		else {
			ans[tmp]++;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}