#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> v;
unordered_set<string> s;

void init() {
	s.insert("i");
	s.insert("pa");
	s.insert("te");
	s.insert("ni");
	s.insert("niti");
	s.insert("a");
	s.insert("ali");
	s.insert("nego");
	s.insert("no");
	s.insert("ili");
}

void func() {
	init();

	string ret = "";
	for (auto x : v) {
		if (s.find(x) == s.end()) {
			ret += (x[0] - 32);
		}
		else {
			if (ret == "") ret += (x[0] - 32);
		}
	}

	cout << ret << '\n';
}

void input() {
	string str;
	while (cin >> str) {
		v.push_back(str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}