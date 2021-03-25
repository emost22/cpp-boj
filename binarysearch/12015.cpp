#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int list[1000001];
int N, ans;

void func() {
	v.push_back(list[1]);
	for (int i = 2; i <= N; i++) {
		if (v[v.size()-1] < list[i]) {
			v.push_back(list[i]);
		}
		else {
			int tmp = lower_bound(v.begin(), v.end(), list[i]) - v.begin();

			v[tmp] = list[i];
		}
	}

	ans = v.size();
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
	cout << ans << '\n';

	return 0;
}