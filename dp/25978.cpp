#include <iostream>
#define MAX 1002
using namespace std;
typedef long long ll;

ll diff[MAX][MAX], dp[MAX][MAX];
int N, M;
bool isInited;

void init() {	 
	isInited = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			diff[i][j] = diff[i][j] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + diff[i][j];
		}
	}
}

void func() {
	int type, x1, y1, x2, y2, k;
	while (M--) {
		cin >> type >> x1 >> y1 >> x2 >> y2;
		x1++;
		y1++;
		x2++;
		y2++;

		if (type == 1) {
			cin >> k;
			
			diff[x2 + 1][y2 + 1] += k;
			diff[x2 + 1][y1] -= k;
			diff[x1][y2 + 1] -= k;
			diff[x1][y1] += k;
		}
		else {
			if (!isInited) init();

			cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];
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