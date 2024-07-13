#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<int> v;
int list[MAX];
int N, K;

void func() {
	for (int i = 1; i < N; i++) {
		v.push_back(list[i] - (list[i - 1] + 1));
	}
	sort(v.begin(), v.end());

	int ret = N;
	int cnt = N;
	int idx = 0;
	while (cnt > K) {
		ret += v[idx++];
		cnt--;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
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