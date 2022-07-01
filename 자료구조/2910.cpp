#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

map<int, pii> m;
vector<pair<int, pii> > v;
int N, C;

void func() {
	for (map<int, pii>::iterator iter = m.begin(); iter != m.end(); iter++) {
		v.push_back({ (*iter).first, {(*iter).second.first, (*iter).second.second} });
	}
	sort(v.begin(), v.end(), [](pair<int, pii> a, pair<int, pii> b) {
		if (a.second.first == b.second.first) return a.second.second < b.second.second;
		else return a.second.first > b.second.first;
	});

	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		for (int j = 0; j < v[i].second.first; j++) {
			cout << v[i].first << ' ';
		}
	}
}

void input() {
	int x;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (m.find(x) == m.end()) {
			m.insert({ x,{1, i} });
		}
		else {
			m[x].first++;
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