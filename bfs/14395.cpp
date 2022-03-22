#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <set>
#define MAX 1000000000
using namespace std;
typedef long long ll;

typedef struct Point {
	ll x;
	string op;
}Point;

set<ll> visit;
ll s, e;

void bfs() {
	queue<Point> q;
	q.push({ s, "" });
	visit.insert(s);

	vector<string> ans;
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			ll x = q.front().x;
			string op = q.front().op;
			q.pop();

			if (x == e) {
				cout << op << '\n';
				return;
			}

			ll nx = x * x;
			if (nx <= MAX && visit.find(nx) == visit.end()) {
				q.push({ nx, op + '*' });
				visit.insert(nx);
			}

			nx = x + x;
			if (nx <= MAX && visit.find(nx) == visit.end()) {
				q.push({ nx, op + '+' });
				visit.insert(nx);
			}

			/*
			nx = x - x;
			if (visit.find(nx) == visit.end()) {
				q.push({ nx, op + '-' });
				visit.insert(nx);
			}
			*/

			if (!x) continue;
			nx = x / x;
			if (visit.find(nx) == visit.end()) {
				q.push({ nx, op + '/' });
				visit.insert(nx);
			}
		}
	}

	cout << "-1\n";
}

void func() {
	if (s == e) {
		cout << "0\n";
		return;
	}
	bfs();
}

void input() {
	cin >> s >> e;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}