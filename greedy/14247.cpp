#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii list[MAX];
int N;

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

void func() {
	sort(list, list + N, cmp);

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i].first + list[i].second * i);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}