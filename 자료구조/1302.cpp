#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> m;
string ans;
int cnt;

void func() {
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (cnt < iter->second) {
			ans = iter->first;
			cnt = iter->second;
		}
		else if (cnt == iter->second) {
			if (ans.compare(iter->first) == 1) {
				ans = iter->first;
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	int N;
	string str;
	cin >> N;
	while (N--) {
		cin >> str;
		if (m.find(str) == m.end()) {
			m.insert({ str, 1 });
		}
		else {
			m.find(str)->second++;
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