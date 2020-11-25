#include <iostream>
#include <stack>
using namespace std;

int list[500001];
int N;

void func() {
	stack<int> st;
	for (int i = 1; i <= N; i++) {
		while (!st.empty() && list[st.top()] < list[i]) {
			st.pop();
		}
		if (st.empty()) cout << "0 ";
		else cout << st.top() << ' ';
		st.push(i);
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
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