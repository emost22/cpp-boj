#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, string> pi;

map<string, int> m;
vector<pi> list;
string str1, str2;
int x, y;

void func() {
	string ans = "";
	int ret = x + y;
	cout << ret << '\n';
	int n = list.size();
	for (int i = 0; i < n; i++) {
		int k = list[i].first;

		while (ret >= k) {
			ret -= k;
			ans += list[i].second;
		}
	}

	cout << ans << '\n';
}

void init() {
	m.insert({ "I", 1 });
	m.insert({ "V", 5 });
	m.insert({ "X", 10 });
	m.insert({ "L", 50 });
	m.insert({ "C", 100 });
	m.insert({ "D", 500 });
	m.insert({ "M", 1000 });
	m.insert({ "CM", 900 });
	m.insert({ "CD", 400 });
	m.insert({ "XC", 90 });
	m.insert({ "XL", 40 });
	m.insert({ "IX", 9 });
	m.insert({ "IV", 4 });
	map<string, int>::iterator iter = m.begin();
	for (; iter != m.end(); iter++) {
		list.push_back({ (*iter).second, (*iter).first });
	}
	sort(list.begin(), list.end(), [](pi a, pi b) {
		return a.first > b.first;
	});

	int len = str1.size();
	for (int i = 0; i < len; i++) {
		string s = "";
		s = str1[i];
		if (i + 1 < len) {
			string ns = "";
			ns = str1[i + 1];
			if (m[s] < m[ns]) {
				s += str1[i + 1];
				i++;
			}
		}
		x += m[s];
	}

	len = str2.size();
	for (int i = 0; i < len; i++) {
		string s = "";
		s = str2[i];
		if (i + 1 < len) {
			string ns = "";
			ns = str2[i + 1];
			if (m[s] < m[ns]) {
				s += str2[i + 1];
				i++;
			}
		}
		x += m[s];
	}
}

void input() {
	cin >> str1 >> str2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}