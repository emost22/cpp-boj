#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;

pi list[MAX];
ll sum;
int N;

void func() {
	ll now = 0;
	for (int i = 0; i < N; i++) {
		now += list[i].second;
		if (now >= (sum + 1) >> 1) {
			cout << list[i].first;
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
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}