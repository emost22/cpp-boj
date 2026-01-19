#include <iostream>
#define MAX 200
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, S, D;

void func(int tc) {
	if (tc > 1) cout << '\n';

	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (S * D < list[i].first) continue;

		ret += list[i].second;
	}

	cout << "Data Set " << tc << ":\n" << ret << '\n';
}

void input() {
	cin >> N >> S >> D;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}