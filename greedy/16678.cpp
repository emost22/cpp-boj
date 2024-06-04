#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int now = 1;
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] < now) continue;
		ret += (ll)(list[i] - now);
		now++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}