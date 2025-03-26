#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 301
using namespace std;

typedef struct Player {
	int level;
	string name;
}Player;

Player list[MAX];
int N, M;

void func() {
	vector<vector<Player> > ret;
	ret.push_back({ list[0] });
	for (int i = 1; i < N; i++) {
		bool flag = false;
		for (auto &r : ret) {
			if (r.size() == M) continue;
			if (r[0].level - 10 > list[i].level || list[i].level > r[0].level + 10) continue;
			flag = true;
			r.push_back(list[i]);
			break;
		}

		if (!flag) ret.push_back({ list[i] });
	}

	for (auto &r : ret) {
		if (r.size() == M) cout << "Started!\n";
		else cout << "Waiting!\n";

		sort(r.begin(), r.end(), [](Player a, Player b) {
			return a.name < b.name;
		});

		for (auto p : r) {
			cout << p.level << ' ' << p.name << '\n';
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i].level >> list[i].name;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}