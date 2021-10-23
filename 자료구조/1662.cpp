#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> s;
string str;
int N;

void func() {
	for (int i = 0; i < N; i++) {
		if (i < N - 1 && str[i + 1] == '(') s.push(str[i] - '0');
		else if (str[i] == '(') s.push(-1);
		else if (str[i] == ')') {
			int len = 0;
			while (1) {
				int x = s.top();
				s.pop();
				if (x == -1) break;

				len += x;
			}
			int cnt = s.top();
			s.pop();
			s.push(cnt * len);
		}
		else s.push(1);
	}

	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
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