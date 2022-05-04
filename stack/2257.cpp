#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<string> s;
string str;
int N;

void func() {
	for (int i = 0; i < N; i++) {
		string tmp = "";
		if (str[i] == ')') {
			while (s.top() != "(") {
				tmp += s.top();
				s.pop();
			}
			s.pop();
			s.push(tmp);
		}
		else if ('2' <= str[i] && str[i] <= '9') {
			for (int j = 0; j < str[i] - '0'; j++) {
				tmp += s.top();
			}
			s.pop();
			s.push(tmp);
		}
		else {
			tmp += str[i];
			s.push(tmp);
		}
	}

	int ans = 0;
	while (!s.empty()) {
		string x = s.top();
		s.pop();
		int len = x.size();
		for (int i = 0; i < len; i++) {
			if (x[i] == 'C') ans += 12;
			else if (x[i] == 'H') ans += 1;
			else ans += 16;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}