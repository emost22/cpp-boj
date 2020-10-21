#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;
int ans = 1;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, s, e;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back(make_pair(e, s));
	}
	sort(v.begin(), v.end());

	s = v[0].second;
	e = v[0].first;
	for (int i = 1; i < N; i++) {
		if (v[i].second >= e) {
			ans++;
			s = v[i].second;
			e = v[i].first;
		}
	}

	cout << ans << '\n';

	return 0;
}