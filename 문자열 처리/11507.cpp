#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<char, int> m;
unordered_set<string> s;
string str;
int N;

void func() {
	for (int i = 0; i < N; i += 3) {
		string subStr = str.substr(i, 3);

		if (s.find(subStr) != s.end()) {
			cout << "GRESKA\n";
			return;
		}

		s.insert(subStr);
		m[subStr[0]]--;
	}

	cout << m['P'] << ' ' << m['K'] << ' ' << m['H'] << ' ' << m['T'] << '\n';
}

void init() {
	m.insert({ 'P', 13 });
	m.insert({ 'K', 13 });
	m.insert({ 'H', 13 });
	m.insert({ 'T', 13 });
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}