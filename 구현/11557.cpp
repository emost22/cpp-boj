#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
typedef pair<string, int> psi;

psi list[MAX];
int N;

bool cmp(psi a, psi b) {
	return a.second > b.second;
}

void func() {
	sort(list, list + N, cmp);
	cout << list[0].first << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}