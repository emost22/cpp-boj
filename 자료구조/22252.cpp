#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

unordered_map<string, priority_queue<ll>> m;
int N;

void func() {
	int type, k;
	string str;

	ll ret = 0;
	while (N--) {
		cin >> type >> str >> k;
		if (type == 1) {
			ll x;
			while (k--) {
				cin >> x;
				m[str].push(x);
			}
		}
		else {
			if (m.find(str) == m.end()) continue;
			while (k--) {
				if (m[str].empty()) break;

				ret += m[str].top();
				m[str].pop();
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}