#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int list[1000000], ans[1000000], N;

void func() {
	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= list[i]) {
			st.pop();
		}
		if (st.empty()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(list[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}