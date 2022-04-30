#include <iostream>
#include <string>
#include <unordered_map>
#define MAX 11
using namespace std;

unordered_map<string, int> m;
char strList[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
string str;
int N, M, K;

void dfs(int x, int y, int cnt, string tmp) {
	if (cnt == 5) return;

	if (m.find(tmp) == m.end()) m.insert({ tmp, 1 });
	else m[tmp]++;

	for (int i = 0; i < 8; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0) nx = N - 1;
		if (ny < 0) ny = M - 1;
		if (nx >= N) nx = 0;
		if (ny >= M) ny = 0;

		dfs(nx, ny, cnt + 1, tmp + strList[nx][ny]);
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			string tmp = "";
			dfs(i, j, 0, tmp + strList[i][j]);
		}
	}

	while (K--) {
		cin >> str;
		cout << m[str] << '\n';
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> strList[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	
	return 0;
}