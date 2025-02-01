#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100002
using namespace std;
typedef pair<int, int> pii;

int list[MAX];
bool chk[MAX];
int N, M, K;

void func() {
	vector<pii> v;
	int sum = 0;
	for (int i = N; i >= 1; i--) {
		sum += list[i];
		if (chk[i]) {
			v.push_back({ sum, i });
			sum = 0;
		}
	}

	sort(v.begin(), v.end(), [](pii a, pii b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	});

	vector<int> ret;
	for (int i = 0; i < M; i++) {
		ret.push_back(v[i].second);
	}

	sort(ret.begin(), ret.end());
	for (auto r : ret) {
		cout << r << '\n';
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	int x;
	for (int i = 0; i < K; i++) {
		cin >> x;
		chk[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}