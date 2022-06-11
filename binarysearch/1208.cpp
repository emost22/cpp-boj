#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 40
using namespace std;
typedef long long ll;

vector<int> a, b;
int list[MAX];
int N, S;
ll ans;

void makeAList(int idx, int sum) {
	if (idx >= N / 2) return;
	int ret = sum + list[idx];
	if (S == ret) ans++;

	a.push_back(ret);
	makeAList(idx + 1, sum);
	makeAList(idx + 1, ret);
}

void makeBList(int idx, int sum) {
	if (idx >= N) return;
	int ret = sum + list[idx];
	if (S == ret) ans++;

	b.push_back(ret);
	makeBList(idx + 1, sum);
	makeBList(idx + 1, ret);
}

void func() {
	makeAList(0, 0);
	makeBList(N / 2, 0);
	
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) {
		int sum = S - a[i];
		ans += (ll)(upper_bound(b.begin(), b.end(), sum) - lower_bound(b.begin(), b.end(), sum));
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> S;
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