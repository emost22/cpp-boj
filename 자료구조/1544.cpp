#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<string> s;
int N;

void func() {
	string str;

	int ret = 0;
	while (N--) {
		cin >> str;
		
		int len = str.size();
		bool flag = true;
		while (len--) {
			if (s.find(str) != s.end()) {
				flag = false;
				break;
			}

			rotate(str.begin(), str.begin() + 1, str.end());
		}

		s.insert(str);
		ret += flag;
	}

	cout << ret << '\n';
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