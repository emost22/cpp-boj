#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

typedef struct shark {
	int si;
	int sp;
	int in;
}shark;

shark num[MAX];
vector<int> list[MAX];
int eat[MAX];
bool chk[MAX];
int N, ans;

bool dfs(int x) {
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (chk[y]) continue;
		chk[y] = true;

		if (eat[y] == 0 || dfs(eat[y])) {
			eat[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i].si >> num[i].sp >> num[i].in;
		for (int j = 1; j < i; j++) {
			if (num[i].si == num[j].si && num[i].sp == num[j].sp && num[i].in == num[j].in) {
				list[i].push_back(j);
			}
			else if (num[i].si >= num[j].si && num[i].sp >= num[j].sp && num[i].in >= num[j].in) {
				list[i].push_back(j);
			}
			else if (num[i].si <= num[j].si && num[i].sp <= num[j].sp && num[i].in <= num[j].in) {
				list[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(chk + 1, chk + 1 + N, false);
		if (dfs(i)) ans++;

		fill(chk + 1, chk + 1 + N, false);
		if (dfs(i)) ans++;
	}

	cout << N - ans << '\n';

	return 0;
}