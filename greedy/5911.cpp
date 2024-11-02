#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii list[MAX];
int N, B;

bool cmp(pii a, pii b) {
	return a.first + a.second < b.first + b.second;
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		pii tmp[MAX];
		copy(begin(list), end(list), begin(tmp));

		tmp[i].first >>= 1;
		sort(tmp, tmp + N, cmp);

		ll sum = 0;
		for (int j = 0; j < N; j++) {
			sum += (tmp[j].first + tmp[j].second);
			if (sum > B) break;
			ret = max(ret, j + 1);
		}

		if (ret == N) break;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}