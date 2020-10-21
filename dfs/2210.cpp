#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;
char list[5][5];
int ans;
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

void dfs(int x, int y, int cnt, string str) {
	if (cnt == 6) {
		if (s.find(str) == s.end()) {
			s.insert(str);
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		dfs(nx, ny, cnt + 1, str + list[nx][ny]);
	}
}

void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string x = "";
			dfs(i, j, 1, x + list[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}