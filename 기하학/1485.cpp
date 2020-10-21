#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<ll, ll> list[4];
vector<ll> v;
int ans;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase;
	ll x, y;

	cin >> Testcase;
	while (Testcase--) {
		for (int i = 0; i < 4; i++) {
			cin >> x >> y;
			
			list[i].first = x;
			list[i].second = y;
			for (int j = 0; j < i; j++) {
				ll x2 = list[j].first;
				ll y2 = list[j].second;
				
				ll dis = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
				v.push_back(dis);
			}
		}
		sort(v.begin(), v.end());

		if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[3] == v[0] && v[4] == v[5]) ans = 1;

		cout << ans << '\n';
		ans = 0;
		v.clear();
	}

	return 0;
}