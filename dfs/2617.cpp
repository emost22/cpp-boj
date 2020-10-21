#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ulist[100], dlist[100];
bool visit[100];
int N, M, ans;

int udfs(int v) {
	int sum = 0;
	visit[v] = true;

	for (int i = 0; i < ulist[v].size(); i++) {
		int next = ulist[v][i];
		if (visit[next]) continue;

		sum += (udfs(next) + 1);
	}

	return sum;
}

int ddfs(int v) {
	int sum = 0;
	visit[v] = true;

	for (int i = 0; i < dlist[v].size(); i++) {
		int next = dlist[v][i];
		if (visit[next]) continue;

		sum += (ddfs(next) + 1);
	}

	return sum;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		ulist[y].push_back(x);
		dlist[x].push_back(y);
	}

	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		if (udfs(i) > N / 2) {
			ans++;
			continue;
		}

		memset(visit, false, sizeof(visit));
		if (ddfs(i) > N / 2) ans++;
	}

	cout << ans << '\n';

	return 0;
}