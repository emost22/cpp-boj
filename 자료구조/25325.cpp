#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
typedef pair<string, int> psi;

map<string, int> m;
int N;

bool cmp(psi a, psi b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

void func() {
	string str;
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		istringstream token(str);
		while (getline(token, str, ' ')) {
			m[str]++;
		}
	}

	vector<psi> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m.insert({ str, 0 });
	}
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}