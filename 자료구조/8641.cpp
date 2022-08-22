#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

unordered_map<ll, ll> m;
vector<ll> ans;
int N;

void func() {
	cout << m.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ' << m[ans[i]] << '\n';
	}
}

void input() {
	int x;
	ll y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (m.find(x) != m.end()) {
			m[x] += y;
		}
		else {
			m.insert({ x,y });
			ans.push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}