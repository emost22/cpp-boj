#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;

void func() {
	sort(v.begin(), v.end());
	cout << v[N - 1] << '\n';
}

void input() {
	int k, x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> x;
			if (j && j < k - 1) continue;

			v.push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}