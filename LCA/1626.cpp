#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 50000
#define LOG 20
using namespace std;

typedef struct edge {
	int u;
	int v;
	int w;
}edge;

vector<pair<int, int> > list[MAX + 1];
vector<edge> v;
pair<int, pair<int, int> > lcaParent[MAX + 1][LOG];
int mstParent[MAX + 1], depth[MAX + 1];
bool visit[MAX + 1];
int mst;
int N, M, cnt;

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

pair<int, int> f(pair<int, int> a, pair<int, int> b) {
	vector<int> nv;
	nv.push_back(a.first);
	nv.push_back(a.second);
	nv.push_back(b.first);
	nv.push_back(b.second);
	sort(nv.rbegin(), nv.rend());
	nv.erase(unique(nv.begin(), nv.end()), nv.end());
	if (nv.size() < 2) nv.push_back(-1);
	return { nv[0], nv[1] };
}

void dfs(int v, int d) {
	depth[v] = d;
	visit[v] = true;

	for (int i = 0; i < list[v].size(); i++) {
		int next = list[v][i].first;
		int w = list[v][i].second;

		if (visit[next]) continue;
		lcaParent[next][0] = { v,{w,-1} };
		dfs(next, d + 1);
	}
}

int find(int v) {
	if (mstParent[v] == v) return v;
	return mstParent[v] = find(mstParent[v]);
}

void Union(int x, int y, int w) {
	int a = find(x);
	int b = find(y);

	if (a == b) return;
	list[x].push_back({ y,w });
	list[y].push_back({ x,w });
	mstParent[b] = a;
	mst += w;
	cnt++;
}

void makeMst() {
	for (int i = 0; i < M; i++) {
		int x = v[i].u;
		int y = v[i].v;
		int w = v[i].w;

		Union(x, y, w);
		if (cnt == N - 1) break;
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		mstParent[i] = i;
	}
	memset(lcaParent, -1, sizeof(lcaParent));
}

pair<int, int> lca(int x, int y) {
	if (depth[x] > depth[y]) swap(x, y);
	pair<int, int> ret = { -1,-1 };

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			ret = f(ret, lcaParent[y][i].second);
			
			y = lcaParent[y][i].first;
		}
	}

	if (x == y) return ret;

	for (int i = LOG - 1; i >= 0; i--) {
		if (lcaParent[x][i].first == 0) continue;
		if (lcaParent[x][i].first != lcaParent[y][i].first) {
			ret = f(ret, lcaParent[x][i].second);
			ret = f(ret, lcaParent[y][i].second);

			x = lcaParent[x][i].first;
			y = lcaParent[y][i].first;
		}
	}

	ret = f(ret, lcaParent[x][0].second);
	ret = f(ret, lcaParent[y][0].second);
	
	return ret;
}

void func() {
	if (cnt < N - 1) {
		cout << "-1\n";
		return;
	}

	dfs(1, 1);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			lcaParent[i][j].first = lcaParent[lcaParent[i][j - 1].first][j - 1].first;
			if (lcaParent[i][j].first == -1) continue;
			lcaParent[i][j].second = f(lcaParent[i][j - 1].second, lcaParent[lcaParent[i][j - 1].first][j - 1].second);
		}
	}

	long long ans = 2147483647;
	for (int i = 0; i < M; i++) {
		int x = v[i].u;
		int y = v[i].v;
		int w = v[i].w;
		pair<int, int> sub = lca(x, y);
		
		if (sub.first != w && sub.first != -1) ans = min(ans, (long long)(mst - sub.first + w));
		else if (sub.second != w && sub.second != -1) ans = min(ans, (long long)(mst - sub.second + w));
	}

	if (ans >= 2147483647) cout << "-1\n";
	else cout << ans << '\n';
}

void input() {
	int x, y;
	int w;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> w;
		v.push_back({ x,y,w });
	}
	sort(v.begin(), v.end(), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	makeMst();
	func();

	return 0;
}