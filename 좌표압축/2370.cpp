#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20001
using namespace std;
typedef pair<int, int> pii;

vector<int> v;
pii list[MAX];
int cnt[MAX];
int visit[MAX];
int N;

void func() {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int num = 1;
	for (int i = 0; i < N; i++) {
		list[i] = { lower_bound(v.begin(), v.end(), list[i].first) - v.begin(), lower_bound(v.begin(), v.end(), list[i].second) - v.begin()};
		for (int j = list[i].first; j <= list[i].second; j++) {
			visit[j] = num;
		}
		num++;
	}

	int ans = 0;
	int pre = -1;
	for (int i = 0; i < MAX; i++) {
		if (!visit[i]) continue;
		if (pre == -1 || (pre != visit[i] && !cnt[visit[i]])) {
			pre = visit[i];
			ans++;
			cnt[visit[i]]++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		v.push_back(list[i].first);
		v.push_back(list[i].second);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}