#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, double> m;
vector<pair<string, double> > v;
double cnt;

void func() {
	unordered_map<string, double>::iterator iter = m.begin();
	for (; iter != m.end(); iter++) {
		iter->second = iter->second * 100 / cnt;
		v.push_back({ iter->first,iter->second });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}

void input() {
	string str;
	while (getline(cin, str)) {
		cnt = cnt + 1.0;
		if (m.find(str) != m.end()) {
			m.find(str)->second = m.find(str)->second + 1.0;
		}
		else m.insert({ str, 1.0 });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed; cout.precision(4);

	input();
	func();

	return 0;
}