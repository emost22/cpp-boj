#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
int parent[200001];
int friends[200001];
int N, idx;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void Union(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a != b) {
		parent[b] = a;
		friends[a] += friends[b];
	}
}

void input() {
	string str1, str2;
	int u, v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str1 >> str2;

		if (m.find(str1) == m.end()) {
			m.insert({ str1, idx });
			parent[idx] = idx;
			friends[idx] = 1;
			u = idx++;
		}
		else {
			u = m[str1];
		}

		if (m.find(str2) == m.end()) {
			m.insert({ str2, idx });
			parent[idx] = idx;
			friends[idx] = 1;
			v = idx++;
		}
		else {
			v = m[str2];
		}

		Union(u, v);

		cout << friends[find(u)] << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		m.clear();
		idx = 0;
	}

	return 0;
}