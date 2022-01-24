#include <iostream>
#include <cstring>
#define MAXROUND 15
#define MAX_N 6
#define MAX_M 3
using namespace std;

const int team1[] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
const int team2[] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
int list[MAX_N][MAX_M], result[MAX_N][MAX_M];

bool dfs(int idx) {
	if (idx == MAXROUND) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_M; j++) {
				if (list[i][j] != result[i][j]) return false;
			}
		}

		return true;
	}

	int t1 = team1[idx];
	int t2 = team2[idx];

	result[t1][0]++;
	result[t2][2]++;
	if (dfs(idx + 1)) return true;
	result[t1][0]--;
	result[t2][2]--;

	result[t1][1]++;
	result[t2][1]++;
	if (dfs(idx + 1)) return true;
	result[t1][1]--;
	result[t2][1]--;

	result[t1][2]++;
	result[t2][0]++;
	if (dfs(idx + 1)) return true;
	result[t1][2]--;
	result[t2][0]--;

	return false;
}

void func() {
	memset(result, 0, sizeof(result));
	if (dfs(0)) cout << "1 ";
	else cout << "0 ";
}

void input() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc = 4;
	while (tc--) {
		input();
		func();
	}
	cout << '\n';

	return 0;
}