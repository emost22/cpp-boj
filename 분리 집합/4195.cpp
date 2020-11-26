#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;
int parent[200001], friends[200001], F, idx;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void input() {
	string s1, s2;
	cin >> F;
	while (F--) {
		cin >> s1 >> s2;
		if (m.find(s1) == m.end()) {
			parent[idx] = idx;
			friends[idx] = 1;
			m.insert({ s1, idx++ });
		}
		if (m.find(s2) == m.end()) {
			parent[idx] = idx;
			friends[idx] = 1;
			m.insert({ s2, idx++ });
		}

		int a = find(m.find(s1)->second);
		int b = find(m.find(s2)->second);

		if (a != b) {
			parent[b] = a;
			friends[a] += friends[b];
		}
		cout << friends[a] << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		idx = 0;
		m.clear();
	}

	return 0;
}