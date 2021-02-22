#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int list[1000001], num[1000001], ans[1000001];
int N;

void print() {
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}

	cout << '\n';
}

void func() {
	for (int i = N; i > 0; i--) {
		while (!s.empty() && num[list[i]] >= num[s.top()]) s.pop();

		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(list[i]);
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		num[list[i]]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	print();

	return 0;
}