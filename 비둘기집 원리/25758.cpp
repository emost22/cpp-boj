#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<string, int> m;
set<string> s;

void func() {
	set<char> ret;
	for (unordered_map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if ((*iter).second < 2) continue;
		ret.insert(max((*iter).first[0], (*iter).first[1]));
	}

	for (set<string>::iterator iter1 = s.begin(); iter1 != s.end(); iter1++) {
		for (set<string>::iterator iter2 = s.begin(); iter2 != s.end(); iter2++) {
			if (iter1 == iter2) continue;
			ret.insert(max((*iter1)[0], (*iter2)[1]));
		}
	}

	cout << ret.size() << '\n';
	for (set<char>::iterator r = ret.begin(); r != ret.end(); r++) {
		cout << (*r) << ' ';
	}
	cout << '\n';
}

void input() {
	int N;
	string str;
	cin >> N;
	while (N--) {
		cin >> str;
		m[str]++;
		s.insert(str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}