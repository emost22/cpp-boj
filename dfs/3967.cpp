#include <iostream>
#include <string>
#include <vector>
#define MAX_N 5
#define MAX_M 9
#define MAX_L 12
using namespace std;
typedef pair<int, int> pii;

string list[MAX_N];
vector<pii> v;
bool used[MAX_L];
int vsize;

int getIntValue(char x) {
	return x - 'A' + 1;
}

void print() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_M; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

bool chk() {
	int sum1 = getIntValue(list[1][1]) + getIntValue(list[1][3]) + getIntValue(list[1][5]) + getIntValue(list[1][7]);
	int sum2 = getIntValue(list[0][4]) + getIntValue(list[1][3]) + getIntValue(list[2][2]) + getIntValue(list[3][1]);
	int sum3 = getIntValue(list[0][4]) + getIntValue(list[1][5]) + getIntValue(list[2][6]) + getIntValue(list[3][7]);
	int sum4 = getIntValue(list[3][1]) + getIntValue(list[3][3]) + getIntValue(list[3][5]) + getIntValue(list[3][7]);
	int sum5 = getIntValue(list[1][1]) + getIntValue(list[2][2]) + getIntValue(list[3][3]) + getIntValue(list[4][4]);
	int sum6 = getIntValue(list[1][7]) + getIntValue(list[2][6]) + getIntValue(list[3][5]) + getIntValue(list[4][4]);

	return sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 && sum5 == sum6;
}

void dfs(int idx) {
	if (idx == vsize) {
		if (chk()) {
			print();
			exit(0);
		}

		return;
	}

	for (int i = 0; i < MAX_L; i++) {
		if (used[i]) continue;

		used[i] = true;
		list[v[idx].first][v[idx].second] = i + 'A';
		dfs(idx + 1);
		list[v[idx].first][v[idx].second] = 'x';
		used[i] = false;
	}
}

void func() {
	dfs(0);
}

void input() {
	for (int i = 0; i < MAX_N; i++) {
		cin >> list[i];
		for (int j = 0; j < MAX_M; j++) {
			if (list[i][j] == 'x') {
				v.push_back({ i, j });
			}
			else if ('A' <= list[i][j] && list[i][j] <= 'Z') {
				used[list[i][j] - 'A'] = true;
			}
		}
	}
	vsize = v.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();
	func();

	return 0;
}