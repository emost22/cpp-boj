#include <iostream>
#define MAX_N 300001
#define MAX_M 1000001
using namespace std;

pair<pair<int, int>, int> list[MAX_N];
bool chk[MAX_M];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!chk[list[i].first.first] && !chk[list[i].first.second] && !chk[list[i].second]) ret++;
		chk[list[i].first.first] = true;
		chk[list[i].first.second] = true;
		chk[list[i].second] = true;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first.first >> list[i].first.second >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}