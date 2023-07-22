#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#define MAX 200001
using namespace std;

string str;
bool chk[MAX];
int N;

void func() {
	stack<int> s;
	for (int i = 0; i < N; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (s.empty()) continue;

			chk[i] = chk[s.top()] = true;
			s.pop();
		}
	}

	int ret = 0;
	int conn = chk[0];
	for (int i = 1; i < N; i++) {
		if (chk[i]) conn++;
		else conn = 0;

		ret = max(ret, conn);
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