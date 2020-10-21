#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define mod 10000
using namespace std;

queue<pair<int, string> > q;
string ans;
int visit[10000], s, e;

void dslr() {
	while (!q.empty()) {
		int x = q.front().first;
		string str = q.front().second;
		q.pop();

		if (x == e) {
			ans = str;
		}

		int next = (x * 2) % mod;
		if (!visit[next]) {
			q.push(make_pair(next, str + "D"));
			visit[next] = 1;
		}
		next = (x - 1) != -1 ? (x - 1) : 9999;
		if (!visit[next]) {
			q.push(make_pair(next, str + "S"));
			visit[next] = 1;
		}
		next = x % 1000 * 10 + x / 1000;
		if (!visit[next]) {
			q.push(make_pair(next, str + "L"));
			visit[next] = 1;
		}
		next = x / 10 + x % 10 * 1000;
		if (!visit[next]) {
			q.push(make_pair(next, str + "R"));
			visit[next] = 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int Testcase;
	
	cin >> Testcase;
	while (Testcase--) {
		cin >> s >> e;
		q.push(make_pair(s, ""));
		visit[s] = 1;
		dslr();

		cout << ans << '\n';
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) q.pop();
	}

	return 0;
}