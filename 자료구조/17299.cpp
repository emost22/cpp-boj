#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int N;
int list[1000001], cnt[1000001], ans[1000001];

void func() {
	for (int i = N; i > 0; i--) {
		while (!s.empty() && cnt[s.top()] <= cnt[list[i]]) s.pop();

		if (s.empty()) {
			ans[i] = -1;
			s.push(list[i]);
		}
		else {
			ans[i] = s.top();
			s.push(list[i]);
		}
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		cnt[list[i]]++;
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