#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

stack<pair<int, int> > s;
int list[500000];
int N;

void func() {
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top().first < list[i]) {
			ans += s.top().second;
			s.pop();
		}

		if (s.empty()) {
			s.push({ list[i],1 });
		}
		else {
			if (s.top().first == list[i]) {
				pair<int, int> p = s.top();
				s.pop();

				ans += p.second;
				if (!s.empty()) ans++;
				s.push({ p.first, p.second + 1 });
			}
			else {
				s.push({ list[i],1 });
				ans++;
			}
		}
	}

	cout << ans << '\n';
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