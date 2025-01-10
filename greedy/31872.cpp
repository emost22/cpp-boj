#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

int list[MAX];
int N, K;

void func() {
	sort(list, list + 1 + N);

	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(list[i] - list[i - 1]);
	}
	sort(v.begin(), v.end());

	int ret = 0;
	for (int i = 0; i < v.size() - K; i++) {
		ret += v[i];
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
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