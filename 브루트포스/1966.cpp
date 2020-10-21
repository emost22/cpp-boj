#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
vector<int> chk;
int Testcase, num, N, M, ans;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> Testcase;
	while (Testcase--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> num;
			q.push(make_pair(i, num));
			chk.push_back(num);
		}
		sort(chk.rbegin(), chk.rend());

		while (1) {
			if (q.front().second == chk[0]) {
				if (q.front().first == M) {
					ans++;
					break;
				}
				chk.erase(chk.begin());
				q.pop();
				ans++;
			}
			else {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				q.push(make_pair(a, b));
			}
		}

		cout << ans << '\n';
		ans = 0;
		while (!q.empty()) q.pop();
		chk.clear();
	}

	return 0;
}