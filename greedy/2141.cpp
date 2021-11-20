#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;

pi list[MAX];
ll leftSum, rightSum;
int N;

void func() {
	int ans = 0;
	ll diff = rightSum;
	for (int i = 0; i < N; i++) {
		rightSum -= list[i].second;

		if (diff > abs(rightSum - leftSum)) {
			diff = abs(rightSum - leftSum);
			ans = list[i].first;
		}
		leftSum += list[i].second;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		rightSum += list[i].second;
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