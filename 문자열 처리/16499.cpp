#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

string str;
int N;

void func() {
	unordered_set<string> s;
	while (N--) {
		cin >> str;
		sort(str.begin(), str.end());

		if (s.find(str) != s.end()) continue;
		s.insert(str);
	}

	cout << s.size() << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}