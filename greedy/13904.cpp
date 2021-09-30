#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
typedef pair<int, int> pi;

pi list[MAX];
bool visit[MAX + 1];
int N;

bool cmp(pi a, pi b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int d = list[i].first;
		for (int j = d; j > 0; j--) {
			if (visit[j]) continue;
			
			visit[j] = true;
			ans += list[i].second;
			break;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	sort(list, list + N, cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}