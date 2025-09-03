#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
int N, M;

void func() {
	cout << abs(v[1].first - v[0].first) + abs(v[1].second - v[0].second) << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x;
			if (!x) continue;
			v.push_back({ i,j });
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