#include <iostream>
#include <stack>
#define MAX 50001
using namespace std;

stack<int> s;
int list[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		while (!s.empty() && s.top() > list[i]) {
			ans++;
			s.pop();
		}

		if (!s.empty() && s.top() == list[i]) continue;

		s.push(list[i]);
	}

	cout << ans << '\n';
}

void input() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		list[i] = y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}