#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool dis[103][103];
int list[103][2];
int N;

void func() {
	for (int k = 1; k <= N + 2; k++) {
		for (int i = 1; i <= N + 2; i++) {
			for (int j = 1; j <= N + 2; j++) {
				if (dis[i][k] && dis[k][j]) dis[i][j] = true;
			}
		}
	}

	if (dis[1][N + 2]) cout << "happy\n";
	else cout << "sad\n";
}

bool getDis(int a[2], int b[2]) {
	return (abs(a[0] - b[0]) + abs(a[1] - b[1])) <= 1000 ? true : false;
}

void init() {
	memset(dis, false, sizeof(dis));
	for (int i = 1; i <= N + 1; i++) {
		for (int j = i + 1; j <= N + 2; j++) {
			if (getDis(list[i], list[j])) {
				dis[i][j] = true;
				dis[j][i] = true;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N + 2; i++) {
		cin >> list[i][0] >> list[i][1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		init();
		func();
	}

	return 0;
}