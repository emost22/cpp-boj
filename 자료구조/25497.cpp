#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int N;

void func() {
	stack<char> s, l;
	int ret = 0;
	for (auto x : str) {
		if ('1' <= x && x <= '9') {
			ret++;
			continue;
		}

		if (x == 'L') l.push(x);
		else if (x == 'S') s.push(x);
		else if (x == 'K') {
			if (s.empty()) break;
			else {
				ret++;
				s.pop();
			}
		}
		else {
			if (l.empty()) break;
			else {
				ret++;
				l.pop();
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}