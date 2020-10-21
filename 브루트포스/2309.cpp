#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, bool> > v;
int ans;

void check(int cnt) {
	if (cnt == 7) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (v[i].second) {
				sum += v[i].first;
			}
		}

		if (sum == 100) {
			ans = 1;
			return;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (!v[i].second) {
			v[i].second = true;
			check(cnt + 1);
			if (ans == 1) return;
			v[i].second = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int data;
	for (int i = 0; i < 9; i++) {
		cin >> data;
		v.push_back(make_pair(data, false));
	}

	check(0);
	sort(v.begin(), v.end());

	for (int i = 0; i < 9; i++) {
		if (v[i].second) {
			cout << v[i].first << '\n';
		}
	}

	return 0;
}