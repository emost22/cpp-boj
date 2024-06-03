#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;

pii list[MAX];
ll sum;
int N;

void func() {
	sort(list, list + N);

	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += list[i].second;
		if ((cnt << 1) >= sum) {
			cout << list[i].first << '\n';
			return;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		sum += list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}