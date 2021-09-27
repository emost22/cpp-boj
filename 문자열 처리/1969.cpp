#include <iostream>
#include <string>
using namespace std;

string str, strAns;
int cnt[50][4];
int N, M, ans;

void func() {
	for (int i = 0; i < M; i++) {
		int idx = 0;
		int maxValue = 0;
		for (int j = 0; j < 4; j++) {
			if (maxValue < cnt[i][j]) {
				maxValue = cnt[i][j];
				idx = j;
			}
		}

		ans += (N - maxValue);

		if (!idx) strAns += 'A';
		else if (idx == 1) strAns += 'C';
		else if (idx == 2) strAns += 'G';
		else strAns += 'T';
	}

	cout << strAns << '\n' << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == 'A') cnt[j][0]++;
			else if (str[j] == 'C') cnt[j][1]++;
			else if (str[j] == 'G') cnt[j][2]++;
			else cnt[j][3]++;
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