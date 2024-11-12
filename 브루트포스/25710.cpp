#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int cnt[MAX];
int N;

void func() {
	vector<int> v;
	for (int i = 1; i < MAX; i++) {
		cnt[i] = min(cnt[i], 2);
		while (cnt[i]--) v.push_back(i);
	}

	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int tmp = v[i] * v[j];
			int sum = 0;
			while (tmp) {
				sum += (tmp % 10);
				tmp /= 10;
			}
			ret = max(ret, sum);
		}
	}
	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}