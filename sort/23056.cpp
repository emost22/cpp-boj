#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, string> list[500];
int cnt[11], N, M, idx;

bool cmp(pair<int, string> a, pair<int, string> b) {
	int x = a.first % 2;
	int y = b.first % 2;

	if (x == y) {
		if (a.first == b.first) {
			if (a.second.size() == b.second.size()) return a.second < b.second;
			else return a.second.size() < b.second.size();
		}
		else return a.first < b.first;
	}
	else {
		return x > y;
	}
}

void func() {
	for (int i = 0; i < idx; i++) {
		cout << list[i].first << ' ' << list[i].second << '\n';
	}
}

void input() {
	int x;
	string str;
	cin >> N >> M;
	while (1) {
		cin >> x >> str;
		if (!x) break;

		if (cnt[x] == M) continue;
		cnt[x]++;
		list[idx] = { x,str };
		idx++;
	}
	sort(list, list + idx, cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}