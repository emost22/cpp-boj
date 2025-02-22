#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

map<string, int> m;
string list[MAX];
int N, M, K;

void func() {
	int mn = 0;
	for (int i = 0; i < K; i++) {
		mn += m[list[i]];
		m[list[i]] = -1;
	}

	vector<int> v;
	for (auto k : m) {
		if (k.second == -1) continue;
		v.push_back(k.second);
	}
	sort(v.begin(), v.end());

	int mx = mn;
	for (int i = 0; i < M - K; i++) {
		mn += v[i];
	}

	for (int i = v.size() - 1; i > (int)v.size() - 1 - M + K; i--) {
		mx += v[i];
	}

	cout << mn << ' ' << mx << '\n';
}

void input() {
	string str;
	int x;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> str >> x;
		m.insert({ str, x });
	}

	for (int i = 0; i < K; i++) {
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