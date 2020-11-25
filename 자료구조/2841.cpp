#include <iostream>
#include <stack>
using namespace std;

int N, P, ans;
stack<int> st[7];

void input() {
	int n, p;
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> n >> p;
		
		while (!st[n].empty() && st[n].top() > p) {
			ans++;
			st[n].pop();
		}

		if (st[n].empty()) {
			ans++;
			st[n].push(p);
		}
		else {
			if (st[n].top() == p) continue;
			st[n].push(p);
			ans++;
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}