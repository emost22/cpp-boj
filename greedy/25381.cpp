#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
string str;
int len;

void func() {
	int ret = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'B') q.push(i);
		else if (str[i] == 'C') {
			if (q.empty()) continue;
			q.pop();
			ret++;
		}
	}

	for (int i = 0; i < len && !q.empty(); i++) {
		while (!q.empty() && q.front() < i) q.pop();
		if (str[i] == 'A') {
			if (q.empty()) continue;
			q.pop();
			ret++;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}