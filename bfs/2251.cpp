#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<pair<int, int>, int> > q;
int solve[201], visit[201][201][201];
int A, B, C, sindex;

void bfs() {
	q.push(make_pair(make_pair(0, 0), C));
	while (!q.empty()) {
		int nowa = q.front().first.first;
		int nowb = q.front().first.second;
		int nowc = q.front().second;
		q.pop();

		if (visit[nowa][nowb][nowc]) continue;
		visit[nowa][nowb][nowc] = 1;

		if (!nowa) solve[sindex++] = nowc;

		if (nowc + nowa > A) {
			q.push(make_pair(make_pair(A, nowb), nowc - (A - nowa)));
		}
		else {
			q.push(make_pair(make_pair(nowa + nowc, nowb), 0));
		}

		if (nowc + nowb > B) {
			q.push(make_pair(make_pair(nowa, B), nowc - (B - nowb)));
		}
		else {
			q.push(make_pair(make_pair(nowa, nowb + nowc), 0));
		}

		if (nowa + nowb > B) {
			q.push(make_pair(make_pair(nowa - (B - nowb), B), nowc));
		}
		else {
			q.push(make_pair(make_pair(0, nowa + nowb), nowc));
		}

		if (nowa + nowc > C) {
			q.push(make_pair(make_pair(nowa - (C - nowc), nowb), C));
		}
		else {
			q.push(make_pair(make_pair(0, nowb), nowa + nowc));
		}

		if (nowb + nowa > A) {
			q.push(make_pair(make_pair(A, nowb - (A - nowa)), nowc));
		}
		else {
			q.push(make_pair(make_pair(nowa + nowb, 0), nowc));
		}

		if (nowb + nowc > C) {
			q.push(make_pair(make_pair(nowa, nowb - (C - nowc)), C));
		}
		else {
			q.push(make_pair(make_pair(nowa, 0), nowb + nowc));
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B >> C;

	bfs();

	sort(solve, solve + sindex);

	for (int i = 0; i < sindex; i++) {
		cout << solve[i] << ' ';
	}
	cout << '\n';

	return 0;
}