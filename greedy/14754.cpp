#include <iostream>
#define MAX 1001
using namespace std;
typedef long long ll;

ll list[MAX][MAX];
bool chk[MAX][MAX];
int N, M;

void func() {
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		int idx = 0;
		for (int j = 0; j < M; j++) {
			ret += list[i][j];
			if (list[i][idx] < list[i][j]) idx = j;
		}
		ret -= list[i][idx];
		chk[i][idx] = true;
	}

	for (int j = 0; j < M; j++) {
		int idx = 0;
		for (int i = 0; i < N; i++) {
			if (list[idx][j] < list[i][j]) idx = i;
		}
		if (chk[idx][j]) continue;
		ret -= list[idx][j];
		chk[idx][j] = true;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
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